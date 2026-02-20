/*===============================================
*   �ļ����ƣ�server.c
*   �� �� �ߣ�zhouhao     
*   �������ڣ�2025��04��25��
*   ��    ����
================================================*/
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include<sqlite3.h>
int mycallback(void *para){}
int main(int argc, char *argv[])
{
       sqlite3 *db;
    //1�������׽���
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("scoket");
        return -1;
    }
    printf("socket success!\n");

    //2����IP��ַ�Ͷ˿ں�
    struct sockaddr_in saddr;  //�����������ַ�ṹ��Ϣ��صĽṹ�����
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(9999);  //�������ֽ���ת��Ϊ�����ֽ����ٸ�ֵ
   // saddr.sin_addr.s_addr = inet_addr("192.168.1.2"); // �����ʮ����ת��Ϊ�����ٸ�ֵ
   saddr.sin_addr.s_addr = INADDR_ANY;


    int s_len = sizeof(saddr);

    int ret = bind(sockfd, (struct sockaddr *)&saddr, s_len);
    if(ret < 0)
    {
        perror("bind");
        return -1;
    }
    printf("bind success!\n");

    //3�����ü����׽���
    ret = listen(sockfd, 5);
    if(ret < 0)
    {
        perror("listen");
        return -1;
    }
    printf("listen success!\n");



    //�����ݿ�
     //1�������ݿ��ļ� -- sqlite3_open();
    int sjk = sqlite3_open("my.db", &db);
    if(sjk != 0)
    {
        //printf("open error!\n");
        printf("open error: %s\n", sqlite3_errmsg(db));  //��ӡ������Ϣ
        return -1;
    }

    //4���ȴ��ͻ�������
    struct sockaddr_in caddr;
    int c_len = sizeof(caddr);
    while(1)
    {
        printf("wait for a new client...\n");
        int connfd = accept(sockfd, (struct sockaddr *)&caddr, &c_len);
        //int connfd = accept(sockfd, NULL, NULL); //ѡ�񲻽��տͻ��˵�IP�Ͷ˿ں���Ϣ
        if(connfd < 0)
        {
            perror("accept");
            continue;
        }
        printf("link success!\n");
		} 
char buf[64] = {0};
char name[64] = {0};
char key[64] = {0};

// �����û���
read(connfd,name,64);
read(connfd,key,64);



// �����û��������������֤�߼�
char sql[256];
char *err_msg = NULL;
char **result;
int rows, cols;

// ��֤�û�������
snprintf(sql, sizeof(sql), "SELECT key FROM user WHERE name='%s'", name);
if(sqlite3_get_table(db, sql, &result, &rows, &cols, &err_msg) != SQLITE_OK) {
    fprintf(stderr, "SQL����: %s\n", err_msg);
    sqlite3_free(err_msg);
    write(connfd, "LOGIN_FAILED", 12);
    close(connfd);
    continue;
}

// ����ѯ���
if(rows == 1) {
    if(strcmp(result[1], key) == 0) {  // ��һ�����������ڶ���������
        write(connfd, "LOGIN_SUCCESS", 13);
        printf("�û� %s ��¼�ɹ�\n", name);
    } else {
        write(connfd, "PASSWORD_ERROR", 14);
        close(connfd);
        continue;
    }
} else {
    write(connfd, "USER_NOT_FOUND", 14);
    close(connfd);
    continue;
}

sqlite3_free_table(result);




while(1){
       	memset(buf, 0, 64);   //�������
            ret = read(connfd, buf, sizeof(buf)-1);

	    if(ret == 0)
            {
                printf("client disconnected!\n");
                break;
            }
            printf("recv %dbytes: %s\n", ret, buf);
            
       }printf("�û������������");
        //6���ر��׽���
        close(connfd);
    }
sqlite3_close(db);
    close(sockfd);

    return 0;
} 


