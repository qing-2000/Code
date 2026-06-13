#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>

#define PORT 8080
#define MAX_CLIENTS_PER_WORKER 1024
#define WORKER_COUNT 4
#define BUFFER_SIZE 1024

// 共享内存：只存退出标志和互斥锁（用于 accept）
typedef struct {
    int quit_flag;
    pthread_mutex_t accept_lock;   // 保护 accept，避免惊群
} SharedData;

SharedData *shm;

void sigint_handler(int sig) {
    if (shm) shm->quit_flag = 1;
}

int create_listen_socket(int port) {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    bind(fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(fd, 128);
    return fd;
}

void worker_process(int serverfd) {
    // 每个子进程私有的客户端 fd 数组
    int client_fds[MAX_CLIENTS_PER_WORKER];
    int client_count = 0;
    fd_set readfds;
    char buf[BUFFER_SIZE];

    while (!shm->quit_flag) {
        FD_ZERO(&readfds);
        FD_SET(serverfd, &readfds);
        int maxfd = serverfd;

        // 只加入本进程的客户端 fd
        for (int i = 0; i < client_count; i++) {
            int fd = client_fds[i];
            if (fd > 0) {
                FD_SET(fd, &readfds);
                if (fd > maxfd) maxfd = fd;
            }
        }

        // select 超时 1 秒，定期检查退出标志
        struct timeval tv = {1, 0};
        int ret = select(maxfd + 1, &readfds, NULL, NULL, &tv);
        if (ret < 0) continue;

        // ----- 新连接（加锁 accept）-----
        if (FD_ISSET(serverfd, &readfds)) {
            pthread_mutex_lock(&shm->accept_lock);
            struct sockaddr_in client_addr;
            socklen_t len = sizeof(client_addr);
            int clientfd = accept(serverfd, (struct sockaddr*)&client_addr, &len);
            pthread_mutex_unlock(&shm->accept_lock);

            if (clientfd > 0 && client_count < MAX_CLIENTS_PER_WORKER) {
                client_fds[client_count++] = clientfd;
                printf("Worker %d: new client fd=%d\n", getpid(), clientfd);
            } else if (clientfd > 0) {
                close(clientfd);  // 本进程客户端已满
            }
            
        }

        // ----- 处理私有客户端的消息 -----
        for (int i = 0; i < client_count; i++) {
            int fd = client_fds[i];
            if (fd <= 0) continue;

            if (FD_ISSET(fd, &readfds)) {
                int n = recv(fd, buf, sizeof(buf) - 1, 0);
                if (n <= 0) {
                    // 客户端断开
                    close(fd);
                    client_fds[i] = client_fds[--client_count];
                } else {
                    // 回显
                    send(fd, buf, n, 0);
                }
            }
        }
    }

    // 退出前关闭所有客户端
    for (int i = 0; i < client_count; i++) {
        close(client_fds[i]);
    }
    close(serverfd);
}

int main() {
    signal(SIGINT, sigint_handler);

    // 创建共享内存
    int shmid = shmget(IPC_PRIVATE, sizeof(SharedData), IPC_CREAT | 0666);
    shm = (SharedData*)shmat(shmid, NULL, 0);
    memset(shm, 0, sizeof(SharedData));

    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&shm->accept_lock, &attr);

    int serverfd = create_listen_socket(PORT);
    printf("Server listening on port %d, workers: %d\n", PORT, WORKER_COUNT);

    // fork 子进程
    for (int i = 0; i < WORKER_COUNT; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            worker_process(serverfd);
            exit(0);
        }
    }

    // 父进程等待
    while (wait(NULL) > 0);
    printf("All workers exited.\n");

    // 清理
    pthread_mutex_destroy(&shm->accept_lock);
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);
    close(serverfd);
    return 0;
}