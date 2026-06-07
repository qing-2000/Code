/*
在 Web 服务器开发中，我们通常希望服务某些满足某个条件的路由。正则表达式便是完成这一目标的工具之一。
给定如下请求结构：
struct Request {
    // request method, POST, GET; path; HTTP version
    std::string method, path, http_version;
    // use smart pointer for reference counting of content
    std::shared_ptr<std::istream> content;
    // hash container, key-value dict
    std::unordered_map<std::string, std::string> header;
    // use regular expression for path match
    std::smatch path_match;
};

请求的资源类型：
typedef std::map<
    std::string, std::unordered_map<
        std::string,std::function<void(std::ostream&, Request&)>>> resource_type;

以及服务端模板：
template <typename socket_type>
class ServerBase {
public:
    resource_type resource;
    resource_type default_resource;

    void start() {
        // TODO
    }
protected:
    Request parse_request(std::istream& stream) const {
        // TODO
    }
}
请实现成员函数 start() 与 parse_request。使得服务器模板使用者可以如下指定路由：

template<typename SERVER_TYPE>
void start_server(SERVER_TYPE &server) {

    // process GET request for /match/[digit+numbers], 
    // e.g. GET request is /match/abc123, will return abc123
    server.resource["fill_your_reg_ex"]["GET"] = 
        [](ostream& response, Request& request) 
    {
        string number=request.path_match[1];
        response << "HTTP/1.1 200 OK\r\nContent-Length: " 
                 << number.length() << "\r\n\r\n" << number;
    };

    // peocess default GET request; 
    // anonymous function will be called 
    // if no other matches response files in folder web/
    // default: index.html
    server.default_resource["fill_your_reg_ex"]["GET"] = 
        [](ostream& response, Request& request) 
    {
        string filename = "www/";

        string path = request.path_match[1];

        // forbidden use `..` access content outside folder web/
        size_t last_pos = path.rfind(".");
        size_t current_pos = 0;
        size_t pos;
        while((pos=path.find('.', current_pos)) != string::npos && pos != last_pos) {
            current_pos = pos;
            path.erase(pos, 1);
            last_pos--;
        }

        // (...)
    };

    server.start();
}
*/
#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <functional>
#include <map>
#include <unordered_map>
#include <memory>
#include <vector>

// 假设的请求结构体
struct Request {
    std::string method, path, http_version;
    std::shared_ptr<std::istream> content;
    std::unordered_map<std::string, std::string> header;
    std::smatch path_match;
};

// 资源类型定义
typedef std::map<
    std::string, std::unordered_map<
        std::string, std::function<void(std::ostream&, Request&)>>> resource_type;

template <typename socket_type>
class ServerBase {
public:
    resource_type resource;
    resource_type default_resource;

    void start() {
        // 创建服务器 socket（假设构造函数自动绑定端口，例如 8080）
        socket_type server(8080);
        while (true) {
            // 接受客户端连接，返回一个连接对象（假设有 input_stream() 和 output_stream() 方法）
            auto client = server.accept();
            std::istream& input = client.input_stream();
            std::ostream& output = client.output_stream();

            // 解析 HTTP 请求
            Request request = parse_request(input);

            // 路由匹配
            bool matched = false;

            // 1. 先尝试匹配精确资源
            for (auto& res : resource) {
                std::regex re(res.first);
                std::smatch match;
                if (std::regex_match(request.path, match, re)) {
                    request.path_match = match;
                    auto& method_map = res.second;
                    auto it = method_map.find(request.method);
                    if (it != method_map.end()) {
                        it->second(output, request);  // 调用对应的处理函数
                        matched = true;
                    }
                    break;  // 匹配第一个成功的正则后停止
                }
            }

            // 2. 如果没有匹配，尝试默认资源（例如处理静态文件）
            if (!matched) {
                for (auto& def : default_resource) {
                    std::regex re(def.first);
                    std::smatch match;
                    if (std::regex_match(request.path, match, re)) {
                        request.path_match = match;
                        auto& method_map = def.second;
                        auto it = method_map.find(request.method);
                        if (it != method_map.end()) {
                            it->second(output, request);
                            matched = true;
                        }
                        break;
                    }
                }
            }

            // 3. 全部未匹配，返回 404 Not Found
            if (!matched) {
                output << "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n";
            }
        }
    }

protected:
    Request parse_request(std::istream& stream) const {
        Request req;
        std::string line;

        // ----- 1. 解析请求行 -----
        std::getline(stream, line);
        if (!line.empty() && line.back() == '\r') {
            line.pop_back(); // 去除 Windows 风格的 \r
        }
        std::istringstream line_stream(line);
        line_stream >> req.method >> req.path >> req.http_version;

        // ----- 2. 解析请求头 -----
        while (std::getline(stream, line) && line != "\r" && line != "") {
            if (line.back() == '\r') {
                line.pop_back();
            }
            size_t colon = line.find(':');
            if (colon != std::string::npos) {
                std::string key = line.substr(0, colon);
                std::string value = line.substr(colon + 1);
                // 去除 value 前导的空格
                size_t start = value.find_first_not_of(" \t");
                if (start != std::string::npos) {
                    value = value.substr(start);
                }
                req.header[key] = value;
            }
        }

        // ----- 3. 解析内容实体（如果有） -----
        auto it = req.header.find("Content-Length");
        if (it != req.header.end()) {
            size_t length = std::stoull(it->second);
            std::vector<char> buffer(length);
            stream.read(buffer.data(), length);
            auto ss = std::make_shared<std::stringstream>();
            ss->write(buffer.data(), length);
            ss->seekg(0);          // 重置读取位置
            req.content = ss;
        } else {
            // 没有消息体，仍提供一个空流以保持一致性
            req.content = std::make_shared<std::stringstream>();
        }

        return req;
    }
};

//伪代码
// 假设 MySocket 是一个实现了上述接口的套接字库
int main() {
    ServerBase<MySocket> server;
    
    // 注册 /match/数字字母 的 GET 处理
    server.resource["/match/([a-zA-Z0-9]+)"]["GET"] =
        [](std::ostream& response, Request& request) {
            std::string number = request.path_match[1];
            response << "HTTP/1.1 200 OK\r\nContent-Length: " 
                     << number.length() << "\r\n\r\n" << number;
        };
    
    // 注册默认文件服务 (正则 "/(.*)")
    server.default_resource["/(.*)"]["GET"] =
        [](std::ostream& response, Request& request) {
            std::string filename = "www/" + std::string(request.path_match[1]);
            // ... 读取文件并输出 ...
        };
    
    server.start();
    return 0;
}