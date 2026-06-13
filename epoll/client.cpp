#include <iostream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>

constexpr int PORT = 8888;
constexpr int BUFFER_SIZE = 4096;

int main() {

    int sockfd = socket(AF_INET,
                        SOCK_STREAM,
                        0);

    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    sockaddr_in server_addr{};

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    inet_pton(AF_INET,
              "127.0.0.1",
              &server_addr.sin_addr);

    if (connect(sockfd,
                (sockaddr*)&server_addr,
                sizeof(server_addr)) < 0) {

        perror("connect");
        return -1;
    }

    std::cout << "connected server"
              << std::endl;

    while (true) {

        std::string msg;

        std::getline(std::cin, msg);

        send(sockfd,
             msg.c_str(),
             msg.size(),
             0);

        char buffer[BUFFER_SIZE] = {0};

        int n = recv(sockfd,
                     buffer,
                     sizeof(buffer),
                     0);

        if (n <= 0) {

            std::cout
                << "server close"
                << std::endl;

            break;
        }

        std::cout
            << "echo: "
            << buffer
            << std::endl;
    }

    close(sockfd);

    return 0;
}