
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include<iostream>
#include<unordered_map>
constexpr int PORT = 8888;
constexpr int MAX_EVENTS = 1024;
constexpr int BUFFER_SIZE = 4096;


// ================================
// 每个客户端连接对象
// ================================
class Connection {
public:

    // socket fd
    int fd;

    // 接收缓冲区
    std::string readBuffer;

    // 发送缓冲区（生产环境会用）
    std::string writeBuffer;
};


// 保存所有连接
std::unordered_map<int, Connection> connections;


// ================================
// 设置 fd 为非阻塞
// ================================
int setNonBlocking(int fd) {

    int flags = fcntl(fd, F_GETFL, 0);

    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}


// ================================
// 封装发送协议
// [4字节长度][正文]
// ================================
void sendMessage(int fd, const std::string& msg) {

    // 消息长度
    uint32_t len = msg.size();

    // 网络字节序
    uint32_t netLen = htonl(len);

    // 发送长度
    send(fd, &netLen, sizeof(netLen), 0);

    // 发送正文
    send(fd, msg.data(), msg.size(), 0);
}


// ================================
// 从 readBuffer 中解析完整包
// ================================
void processMessages(Connection& conn) {

    while (true) {

        // 至少需要4字节长度字段
        if (conn.readBuffer.size() < 4) {
            return;
        }

        // 读取长度字段
        uint32_t netLen;

        memcpy(&netLen,
               conn.readBuffer.data(),
               4);

        // 转回主机字节序
        uint32_t bodyLen = ntohl(netLen);

        // 完整包长度不够
        if (conn.readBuffer.size() < 4 + bodyLen) {
            return;
        }

        // 提取正文
        std::string msg = conn.readBuffer.substr(4, bodyLen);

        std::cout << "recv from "
                  << conn.fd
                  << ": "
                  << msg
                  << std::endl;

        // 回显
        sendMessage(conn.fd, msg);

        // 删除已经处理的数据
        conn.readBuffer.erase(0, 4 + bodyLen);
    }
}
int main() {
      // ================================
    // 1. 创建监听 socket
    // ================================
    int listen_fd = socket(AF_INET,
                           SOCK_STREAM,
                           0);

    if (listen_fd < 0) {
        perror("socket");
        return -1;
    }


    // ================================
    // 2. 允许端口复用
    // ================================
    int opt = 1;

    setsockopt(listen_fd,
               SOL_SOCKET,
               SO_REUSEADDR,
               &opt,
               sizeof(opt));


    // ================================
    // 3. 非阻塞
    // ================================
    setNonBlocking(listen_fd);


    // ================================
    // 4. 绑定地址
    // ================================
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;


    if (bind(listen_fd,
             (sockaddr*)&serverAddr,
             sizeof(serverAddr)) < 0) {

        perror("bind");
        return -1;
    }


    // ================================
    // 5. 开始监听
    // ================================
    if (listen(listen_fd,
               SOMAXCONN) < 0) {

        perror("listen");
        return -1;
    }
    // ================================
    // 6. 创建 epoll 实例
    // ================================
    int epfd = epoll_create1(0);

    if (epfd < 0) {
        perror("epoll_create1");
        return -1;
    }


 // ================================
    // 7. 注册监听 socket
    // ================================
    epoll_event ev{};

    ev.data.fd = listen_fd;

    // ET 边缘触发
    ev.events = EPOLLIN | EPOLLET;


    epoll_ctl(epfd,
              EPOLL_CTL_ADD,
              listen_fd,
              &ev);


    std::cout << "epoll server start..." << std::endl;


    // epoll 返回的活跃事件数组
    epoll_event events[MAX_EVENTS];


    while (true) {

        // ================================
        // 8. 等待活跃事件
        // ================================
        int nready = epoll_wait(epfd,
                                events,
                                MAX_EVENTS,
                                -1);

        if (nready < 0) {
            perror("epoll_wait");
            break;
        }
        // ================================
        // 9. 遍历活跃事件
        // ================================
        for (int i = 0; i < nready; ++i) {

            int fd = events[i].data.fd;


            // ================================
            // 新连接到来
            // ================================
            if (fd == listen_fd) {

                while (true) {

                    sockaddr_in clientAddr{};
                    socklen_t len = sizeof(clientAddr);


                    int client_fd = accept(listen_fd,
                                           (sockaddr*)&clientAddr,
                                           &len);
                    // ET 必须 accept 到 EAGAIN
                    if (client_fd < 0) {

                        if (errno == EAGAIN ||
                            errno == EWOULDBLOCK) {
                            break;
                        }

                        perror("accept");
                        break;
                    }


                    // 设置非阻塞
                    setNonBlocking(client_fd);


                    // 保存连接对象
                    Connection conn;
                    conn.fd = client_fd;

                    connections[client_fd] = conn;


                    // 注册客户端 fd
                    epoll_event clientEv{};

                    clientEv.data.fd = client_fd;

                    clientEv.events = EPOLLIN | EPOLLET;


                    epoll_ctl(epfd,
                              EPOLL_CTL_ADD,
                              client_fd,
                              &clientEv);


                    std::cout << "new client: "
                              << client_fd
                              << std::endl;
                }
            }
                        // ================================
            // 客户端可读事件
            // ================================
            else if (events[i].events & EPOLLIN) {

                Connection& conn = connections[fd];


                while (true) {

                    char buffer[BUFFER_SIZE];

                    int n = recv(fd,
                                 buffer,
                                 sizeof(buffer),
                                 0);


                    // 客户端关闭
                    if (n == 0) {

                        std::cout << "client close: "
                                  << fd
                                  << std::endl;

                        close(fd);

                        epoll_ctl(epfd,
                                  EPOLL_CTL_DEL,
                                  fd,
                                  nullptr);

                        connections.erase(fd);

                        break;
                    }


                    // recv 错误
                    if (n < 0) {

                        // ET模式：读完了
                        if (errno == EAGAIN ||
                            errno == EWOULDBLOCK) {

                            break;
                        }

                        close(fd);

                        epoll_ctl(epfd,
                                  EPOLL_CTL_DEL,
                                  fd,
                                  nullptr);

                        connections.erase(fd);

                        break;
                    }


                    // 将收到的数据追加到连接缓冲区
                    conn.readBuffer.append(buffer, n);
                }


                // 尝试解析完整协议包
                processMessages(conn);
            }
        }
    }

    close(listen_fd);
    close(epfd);

    return 0;
}