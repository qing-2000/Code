//windows网络编程,基于winsocket
#include<iostream>
#include<string>
#include<winsock2.h>
#include<windows.h>
using namespace std;
#pragma comment(lib,"w2_32.lib")
int main(){
    WSADATA wsaData;
    SOCKET clientSocket;
    SOCKADDR_IN serverAddr;

    // 初始化 Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Winsock 初始化失败" << std::endl;
        return 1;
    }

    // 创建 TCP 套接字
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "套接字创建失败" << std::endl;
        WSACleanup();
        return 1;
    }

    // 连接到服务器
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("192.168.126.1");
    serverAddr.sin_port = htons(8848);

    if (connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "连接服务器失败" << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    while (true) {
    // 发送请求
        //中间数组存储输入内容
        const int len=1024;
        char arr[len];
        const char* msg;// = "Hello, Server!";
        cout<<"输入内容：";
        cin.getline(arr,len);
        msg=arr; 
        send(clientSocket, msg, strlen(msg), 0);

    // 接收响应
        char buffer[1024];
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0';
            std::cout << "接收到的数据: " << buffer << std::endl;
        } else if (bytesReceived == 0) {
            std::cout << "服务器关闭了连接" << std::endl;
            break;  // 如果服务器关闭了连接，退出循环
        } else {
            std::cerr << "接收错误" << std::endl;
            break;  // 出现错误则退出循环
        }

    /* 假设你有一个条件判断来退出循环
    if (someConditionToExit) {
            break;
        }
    }*/
    }
    closesocket(clientSocket);
    WSACleanup();

    return 0;
}