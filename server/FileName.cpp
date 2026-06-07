/*===============================================
*   文件名称：server.c
*   创 建 者：zhouhao
*   创建日期：2025年04月25日
*   描    述：
================================================*/
#include <stdio.h>
//#include <strings.h>
#include <stdlib.h>
#include <string.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <sys/types.h>
//#include <unistd.h>
//#include<sqlite3.h>
int mycallback(void* para) {}
int main(int argc, char* argv[])
{
    sqlite3* db;
    //1、创建套接字
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("scoket");
        return -1;
    }
    printf("socket success!\n");

    //2、绑定IP地址和端口号
    struct sockaddr_in saddr;  //定义服务器地址结构信息相关的结构体变量
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(9999);  //将本机字节序转换为网络字节序再赋值
    // saddr.sin_addr.s_addr = inet_addr("192.168.1.2"); // 将点分十进制转换为整形再赋值
    saddr.sin_addr.s_addr = INADDR_ANY;


    int s_len = sizeof(saddr);

    int ret = bind(sockfd, (struct sockaddr*)&saddr, s_len);
    if (ret < 0)
    {
        perror("bind");
        return -1;
    }
    printf("bind success!\n");

    //3、设置监听套接字
    ret = listen(sockfd, 5);
    if (ret < 0)
    {
        perror("listen");
        return -1;
    }
    printf("listen success!\n");



    //打开数据库
     //1、打开数据库文件 -- sqlite3_open();
    int sjk = sqlite3_open("my.db", &db);
    if (sjk != 0)
    {
        //printf("open error!\n");
        printf("open error: %s\n", sqlite3_errmsg(db));  //打印错误信息
        return -1;
    }

    //4、等待客户端连接
    struct sockaddr_in caddr;
    int c_len = sizeof(caddr);
    while (1)
    {
        printf("wait for a new client...\n");
        int connfd = accept(sockfd, (struct sockaddr*)&caddr, &c_len);
        //int connfd = accept(sockfd, NULL, NULL); //选择不接收客户端的IP和端口号信息
        if (connfd < 0)
        {
            perror("accept");
            continue;
        }
        printf("link success!\n");
    }
    char buf[64] = { 0 };
    char name[64] = { 0 };
    char key[64] = { 0 };

    // 接收用户名
    read(connfd, name, 64);
    read(connfd, key, 64);



    // 接收用户名密码后添加验证逻辑
    char sql[256];
    char* err_msg = NULL;
    char** result;
    int rows, cols;

    // 验证用户名密码
    snprintf(sql, sizeof(sql), "SELECT key FROM user WHERE name='%s'", name);
    if (sqlite3_get_table(db, sql, &result, &rows, &cols, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL错误: %s\n", err_msg);
        sqlite3_free(err_msg);
        write(connfd, "LOGIN_FAILED", 12);
        close(connfd);
        continue;
    }

    // 检查查询结果
    if (rows == 1) {
        if (strcmp(result[1], key) == 0) {  // 第一行是列名，第二行是数据
            write(connfd, "LOGIN_SUCCESS", 13);
            printf("用户 %s 登录成功\n", name);
        }
        else {
            write(connfd, "PASSWORD_ERROR", 14);
            close(connfd);
            continue;
        }
    }
    else {
        write(connfd, "USER_NOT_FOUND", 14);
        close(connfd);
        continue;
    }

    sqlite3_free_table(result);




    while (1) {
        memset(buf, 0, 64);   //清空数组
        ret = read(connfd, buf, sizeof(buf) - 1);

        if (ret == 0)
        {
            printf("client disconnected!\n");
            break;
        }
        printf("recv %dbytes: %s\n", ret, buf);

    }printf("用户名或密码错误。");
    //6、关闭套接字
    close(connfd);
}
sqlite3_close(db);
close(sockfd);

return 0;
}


