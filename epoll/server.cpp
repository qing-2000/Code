#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

constexpr int PORT = 8888;
constexpr int MAX_EVENTS = 1024;
constexpr int BUFFER_SIZE = 4096;


// 设置非阻塞
int setNonBlocking(int fd) {

    int flags = fcntl(fd, F_GETFL, 0);

    return fcntl(fd,
                 F_SETFL,
                 flags | O_NONBLOCK);
}


int main() {

    // 1. 创建监听socket
    int listen_fd = socket(AF_INET,
                           SOCK_STREAM,
                           0);

    if (listen_fd < 0) {
        perror("socket");
        return -1;
    }

    // 端口复用
    int opt = 1;

    setsockopt(listen_fd,
               SOL_SOCKET,
               SO_REUSEADDR,
               &opt,
               sizeof(opt));

    // 非阻塞
    setNonBlocking(listen_fd);

    // 2. 绑定
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

    // 3. 监听
    if (listen(listen_fd,
               SOMAXCONN) < 0) {

        perror("listen");
        return -1;
    }

    // 4. 创建epoll实例
    //int epoll_create1(int flag),flag默认0,即EPOLL_CLOEXEC默认exec后关闭
    int epfd = epoll_create1(0);

    if (epfd < 0) {
        perror("epoll_create1");
        return -1;
    }

    // 5. 注册监听fd
    epoll_event ev{};

    //data.fd保持socket_fd
    ev.data.fd = listen_fd;

    // ET边缘触发
    ev.events = EPOLLIN | EPOLLET;

    epoll_ctl(epfd,
              EPOLL_CTL_ADD,
              listen_fd,
              &ev);

    std::cout << "epoll server start..."
              << std::endl;

    // 事件数组
    epoll_event events[MAX_EVENTS];

    while (true) {

        // 6. 等待事件   epoll_wait从ready list取活跃fd,高性能核心
        int nready = epoll_wait(
            epfd,
            events,
            MAX_EVENTS,
            -1
        );

        if (nready < 0) {
            perror("epoll_wait");
            break;
        }

        // 遍历活跃事件
        for (int i = 0; i < nready; ++i) {

            int fd = events[i].data.fd;

            // 新连接
            if (fd == listen_fd) {

                while (true) {

                    sockaddr_in client_addr{};
                    socklen_t len = sizeof(client_addr);

                    int client_fd = accept(
                        listen_fd,
                        (sockaddr*)&client_addr,
                        &len
                    );

                    // ET模式必须accept到没有
                    if (client_fd < 0) {

                        if (errno == EAGAIN ||
                            errno == EWOULDBLOCK) {
                            break;
                        }

                        perror("accept");
                        break;
                    }

                    // 非阻塞
                    setNonBlocking(client_fd);

                    epoll_event client_ev{};

                    client_ev.data.fd = client_fd;

                    // ET模式
                    client_ev.events =
                        EPOLLIN | EPOLLET;

                    epoll_ctl(epfd,
                              EPOLL_CTL_ADD,
                              client_fd,
                              &client_ev);

                    std::cout << "new client: "
                              << client_fd
                              << std::endl;
                }
            }

            // 客户端数据
            else if (events[i].events & EPOLLIN) {

                while (true) {

                    char buffer[BUFFER_SIZE];

                    memset(buffer,
                           0,
                           sizeof(buffer));

                    int n = recv(fd,
                                 buffer,
                                 sizeof(buffer),
                                 0);

                    // 客户端关闭
                    if (n == 0) {

                        std::cout
                            << "client close: "
                            << fd
                            << std::endl;

                        close(fd);

                        epoll_ctl(epfd,
                                  EPOLL_CTL_DEL,
                                  fd,
                                  nullptr);

                        break;
                    }

                    // ET模式读完
                    if (n < 0) {
                        //EAGAIN内核缓冲区空了
                        if (errno == EAGAIN || 
                            errno == EWOULDBLOCK) {

                            break;
                        }

                        close(fd);

                        epoll_ctl(epfd,
                                  EPOLL_CTL_DEL,
                                  fd,
                                  nullptr);

                        break;
                    }

                    std::cout
                        << "recv from client"
                        << fd
                        << ": "
                        << buffer
                        << std::endl;

                    // 回显
                    send(fd,
                         buffer,
                         n,
                         0);
                }
            }
        }
    }

    close(listen_fd);

    close(epfd);

    return 0;
}