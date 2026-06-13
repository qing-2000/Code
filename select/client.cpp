#include <iostream>
#include <cstring>      // memset, strlen, strcspn
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>     // close

using namespace std;

int main() {
    // 1. 创建 socket
    int ClientSock = socket(AF_INET, SOCK_STREAM, 0);
    if (ClientSock < 0) {
        cerr << "socket 创建失败\n";
        return -1;
    }

    // 2. 设置服务器地址
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        cerr << "IP 地址转换失败\n";
        close(ClientSock);
        return -1;
    }

    // 3. 连接
    if (connect(ClientSock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        cerr << "connect 失败\n";
        close(ClientSock);
        return -1;
    }

    // 4. 发送
    char buffer[1024];
    string end="%end";
    while(1){
        cout << "输入要发送到服务器的信息：";
        cin.getline(buffer, 1024);

        // 去掉换行符（如果有）
        buffer[strcspn(buffer, "\n")] = '\0';

        if (send(ClientSock, buffer, strlen(buffer), 0) <= 0) {
            cerr << "send 失败\n";
            close(ClientSock);
            return -1;
        }

        if(strcmp(buffer,"%end")==0){
            break;
        }

        // 5. 清空 buffer 并接收回显
        memset(buffer, 0, 1024);                  
        int bytes = recv(ClientSock, buffer, sizeof(buffer) - 1, 0);
        if (bytes <= 0) {
            cerr << "回显接收失败或服务器关闭连接\n";
            close(ClientSock);
            return -1;
        }
        else {
            buffer[bytes] = '\0';
            cout << "收到回显：" << buffer << endl;  
            
        }
        memset(buffer,0,sizeof(buffer)-1);
    }

    // 6. 关闭
    cout << "通信结束，关闭客户端。" << endl;
    close(ClientSock);
    return 0;
}