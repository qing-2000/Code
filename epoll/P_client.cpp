#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

constexpr int PORT = 8888;


// ================================
// 发送长度协议
// ================================
void sendMessage(int fd, const std::string& msg) {

    uint32_t len = msg.size();

    uint32_t netLen = htonl(len);

    send(fd, &netLen, 4, 0);

    send(fd, msg.data(), msg.size(), 0);
}


// ================================
// 接收完整消息
// ================================

std::string recvMessage(int fd) {

    // 读取4字节长度
    uint32_t netLen;

    recv(fd, &netLen, 4, MSG_WAITALL);

    uint32_t bodyLen = ntohl(netLen);


    // 读取正文
    std::string msg;

    msg.resize(bodyLen);

    recv(fd,
         msg.data(),
         bodyLen,
         MSG_WAITALL);

    return msg;
}


int main() {

    int sockfd = socket(AF_INET,
                        SOCK_STREAM,
                        0);

    if (sockfd < 0) {
        perror("socket");
        return -1;
    }


    sockaddr_in serverAddr{};

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);

    inet_pton(AF_INET,
              "127.0.0.1",
              &serverAddr.sin_addr);


    if (connect(sockfd,
                (sockaddr*)&serverAddr,
                sizeof(serverAddr)) < 0) {

        perror("connect");
        return -1;
    }


    std::cout << "connected server" << std::endl;


    while (true) {

        std::string msg;

        std::getline(std::cin, msg);


        sendMessage(sockfd, msg);


        std::string echo = recvMessage(sockfd);

        std::cout << "echo: "
                  << echo
                  << std::endl;
    }


    close(sockfd);

    return 0;
}