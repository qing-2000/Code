#include <iostream>
#include <cstring>      // memset, strlen, strcspn
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>     // close

using namespace std;
int main(){
    int serverfd,clientfd;
    
    char buffer[1024];
    string end="%end";
    
    serverfd=socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in addr;
    socklen_t addrlen=sizeof(addr);
    
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=INADDR_ANY;
    addr.sin_port=htons(8080);


    struct sockaddr_in client_addr;   // 给 accept 用
    socklen_t client_len = sizeof(client_addr);

    //bind
    if(bind(serverfd,(struct sockaddr*)&addr,sizeof(addr))<0){
        cerr<<"bind error"<<"\n";
    }

    //listen
    if(listen(serverfd,1)<0){
        cerr<<"listen error"<<"\n";
    }
    //accept
    clientfd=accept(serverfd,(struct sockaddr*)&addr,&client_len);
    if(clientfd<0){            
        cerr<<"accept error"<<"\n";
    }
    while(1){
        //recv
        int message=recv(clientfd,buffer,sizeof(buffer)-1,0);
        //结尾加0转为字符串
        buffer[message]='\0';

        if(strcmp(buffer,"%end")==0){
            cout<<"收到结束信号，结束通信。"<<"\n";
            break;
        }
        cout<<"收到客户端的消息："<<buffer<<"\n";

        //回显
        if(send(clientfd,buffer,strlen(buffer),0)<=0){
            cerr<<"回显失败"<<"\n";
            break;
        }
        memset(buffer,0,sizeof(buffer)-1);
    }

    cout<<"通信结束，服务器关闭。"<<"\n";

    //close
    close(clientfd);
    close(serverfd);
    return 0;
}