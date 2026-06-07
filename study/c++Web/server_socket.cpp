//windows网络编程,基于winsocket
#include<iostream>
#include<winsock2.h>
#include<windows.h>
using namespace std;
#pragma comment(lib,"ws2_32.lib")
int main(){
    //192.168.126.1
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    SOCKADDR_IN serverAddr, clientAddr;
    int clientAddrSize = sizeof(clientAddr);


    // 初始化 Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Winsock 初始化失败" << std::endl;
        return 1;
    }

     // 创建 TCP 套接字
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "套接字创建失败" << std::endl;
        WSACleanup();
        return 1;
    }


     // 绑定套接字到本地 IP 和端口
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8848);
    
    if (bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "绑定失败" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // 开始监听客户端连接
    if (listen(serverSocket, 5) == SOCKET_ERROR) {
        std::cerr << "监听失败" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "等待客户端连接..." << std::endl;

    // 接受客户端连接
    clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &clientAddrSize);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "接受连接失败" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "客户端连接成功！" << std::endl;

    while (true) {
        char buffer[1024];
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0';
            std::cout << "接收到的数据: " << buffer << std::endl;

        // 发送回应
            const char* reply = "Message received!";
            send(clientSocket, reply, strlen(reply), 0);
        } else if (bytesReceived == 0) {
                std::cout << "客户端断开连接" << std::endl;
            break;  // 如果客户端断开连接，则退出循环
        } else {
            std::cerr << "接收错误" << std::endl;
            break;  // 出现错误则退出循环
        }
    }

    // 关闭连接
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}