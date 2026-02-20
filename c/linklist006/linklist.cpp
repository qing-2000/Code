#include<stdio.h>
#include<stdlib.h>
#include<String.h>
#include <time.h>

typedef int INTEGER;
typedef struct node {
    INTEGER data;
    struct node* next;
}*pNUMLINK;
INTEGER testscore(pNUMLINK h, int score) {
    while (h != NULL) {
        if (h->data == score) {
            return 1;
        }
        h = h->next;
    }
    return 0;
}
void createLink(pNUMLINK& h) {
    for (int i = 0; i < 20; ++i) {
        INTEGER score = rand() % 100 + 1;
        while (testscore(h, score)) score = rand() % 100 + 1;

        pNUMLINK newNode = (pNUMLINK)malloc(sizeof(struct node));
        newNode->data = score;
        newNode->next = NULL;

        if (h == NULL) {
            h = newNode;
        }
        else {
            newNode->next = h;
            h = newNode;
        }
    }
}
void outLINK(pNUMLINK h) {
    int i = 0;
    while (h != NULL) {
        if (i % 10 == 0)
            printf("\n");
        printf("%6d", h->data);
        h = h->next;
        i++;
    }
}
void insertnode(pNUMLINK& h, INTEGER key) {
    pNUMLINK temp = h, p;
    p = (pNUMLINK)malloc(sizeof(node));
    if (!p) {  // 检查malloc是否成功
        printf("Memory allocation error.\n");
        exit(1);  // 如果内存分配失败，退出程序
    }
    p->data = key;
    //p->next = NULL;
    p->next = h;
    h = p;
}
void delnode(pNUMLINK h) {
    pNUMLINK p = h, q = h->next;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    free(q);
    p->next = NULL;
}
int main() {
    pNUMLINK h = NULL;
    INTEGER key;
    printf("你好");
    createLink(h);
    outLINK(h);
    //printf("\n输入要在头插入的数据：");
    //scanf_s("%d", &key);
    //insertnode(h, key);
    printf("\n删除最后一个节点后：");
    delnode(h);
    outLINK(h);
    printf("\n");
    system("pause");
    return 0;
}