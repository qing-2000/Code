#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/select.h>

using namespace std;

int main() {
    int serverfd;
    char buffer[1024];

    serverfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);

    if (bind(serverfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        cerr << "bind error\n";
        return -1;
    }

    if (listen(serverfd, 5) < 0) {
        cerr << "listen error\n";
        return -1;
    }

    // 客户端数组
    int clients[5] = {0};      // 初始化为 0

    fd_set readfds;
    int maxfd;

    cout << "服务器启动，等待连接...\n";

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(serverfd, &readfds);      // 监听新连接
        maxfd = serverfd;

        // 把所有活跃的客户端加入集合
        for (int i = 0; i < 5; i++) {
            if (clients[i] > 0) {
                FD_SET(clients[i], &readfds);
                if (clients[i] > maxfd) maxfd = clients[i];
            }
        }

        struct timeval tv;
        tv.tv_sec = 30;    // 30 秒无任何事件就退出
        tv.tv_usec = 0;

        int ret = select(maxfd + 1, &readfds, NULL, NULL, &tv);//最后为超时参数，null为完全阻塞。struct timeval tv = {0, 0};完全非阻塞，立即返回（轮询）。struct timeval tv = {sec, usec};	定时阻塞，等待指定时间，超时后返回 0
        
        if (ret == 0) {
            cout << "超时无活动，退出\n";
            break;
        }
        if (ret < 0) {
            cerr << "select error\n";
            break;
        }

        // 检查是否有新连接
        if (FD_ISSET(serverfd, &readfds)) {
            struct sockaddr_in client_addr;
            socklen_t client_len = sizeof(client_addr);
            int newfd = accept(serverfd, (struct sockaddr*)&client_addr, &client_len);
            if (newfd < 0) {
                cerr << "accept error\n";
                continue;
            }
            // 存入空位
            for (int i = 0; i < 5; i++) {
                if (clients[i] == 0) {
                    clients[i] = newfd;
                    cout << "客户端 " << i << " 已连接\n";
                    break;
                }
            }
        }

        // 检查已有客户端是否有数据
        for (int i = 0; i < 5; i++) {
            int fd = clients[i];
            if (fd > 0 && FD_ISSET(fd, &readfds)) {
                memset(buffer, 0, sizeof(buffer));
                int bytes = recv(fd, buffer, sizeof(buffer) - 1, 0);

                if (bytes <= 0) {
                    // 客户端断开
                    cout << "客户端 " << i << " 断开\n";
                    close(fd);
                    clients[i] = 0;
                } else {
                    buffer[bytes] = '\0';
                    cout << "收到客户端[" << i << "]的消息：" << buffer << endl;
                    if (strcmp(buffer, "%end") == 0) {
                        cout << "客户端 " << i << " 请求结束通信\n";
                        send(fd, "bye", 3, 0);
                        close(fd);
                        clients[i] = 0;
                    } else {
                        // 回显
                        send(fd, buffer, strlen(buffer), 0);
                    }
                }
            }
        }
    }

    // 清理
    for (int i = 0; i < 5; i++) {
        if (clients[i] > 0) close(clients[i]);
    }
    close(serverfd);
    return 0;
}