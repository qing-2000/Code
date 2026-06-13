#include <iostream>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <poll.h>

constexpr int PORT = 8888;
constexpr int BUFFER_SIZE = 1024;
constexpr int MAX_CONNECTIONS = 1024;

int main() {
    // 1. 创建监听socket
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_fd < 0) {
        perror("socket");
        return -1;
    }

    // 允许端口复用
    int opt = 1;
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 2. 绑定地址
    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_fd,
             (sockaddr*)&server_addr,
             sizeof(server_addr)) < 0) {
        perror("bind");
        return -1;
    }

    // 3. 开始监听
    if (listen(listen_fd, SOMAXCONN) < 0) {
        perror("listen");
        return -1;
    }

    std::cout << "poll server start at port "
              << PORT << std::endl;

    // pollfd数组
    std::vector<pollfd> fds;

    // 监听socket加入poll
    pollfd listen_pollfd{};
    listen_pollfd.fd = listen_fd;
    listen_pollfd.events = POLLIN;

    fds.push_back(listen_pollfd);

    while (true) {

        // 4. poll监听
        int ret = poll(fds.data(),
                       fds.size(),
                       -1);

        if (ret < 0) {
            perror("poll");
            break;
        }

        // 遍历所有fd
        for (size_t i = 0; i < fds.size(); ++i) {

            // 监听socket有新连接
            if (fds[i].fd == listen_fd &&
                (fds[i].revents & POLLIN)) {

                sockaddr_in client_addr{};
                socklen_t len = sizeof(client_addr);

                int client_fd = accept(
                    listen_fd,
                    (sockaddr*)&client_addr,
                    &len
                );

                if (client_fd < 0) {
                    perror("accept");
                    continue;
                }

                std::cout << "new client: "
                          << client_fd
                          << std::endl;

                // 新客户端加入poll
                pollfd client_pollfd{};
                client_pollfd.fd = client_fd;
                client_pollfd.events = POLLIN;

                fds.push_back(client_pollfd);
            }

            // 普通客户端可读
            else if (fds[i].revents & POLLIN) {

                char buffer[BUFFER_SIZE] = {0};

                int n = recv(
                    fds[i].fd,
                    buffer,
                    BUFFER_SIZE,
                    0
                );

                // 客户端断开
                if (n <= 0) {

                    std::cout << "client disconnect: "
                              << fds[i].fd
                              << std::endl;

                    close(fds[i].fd);

                    // 删除fd
                    fds.erase(fds.begin() + i);

                    --i;
                }
                else {

                    std::cout << "recv from client"
                              << fds[i].fd
                              << ": "
                              << buffer
                              << std::endl;

                    // 回显
                    send(
                        fds[i].fd,
                        buffer,
                        n,
                        0
                    );
                }
            }
        }
    }

    close(listen_fd);

    return 0;
}