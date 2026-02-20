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
    h = new node{ 0,NULL };
    //pNUMLINK temp = h;
    for (int i = 0; i < 20; ++i) {
        INTEGER score = rand() % 100 + 1;
        while (testscore(h, score)) score = rand() % 100 + 1;

        pNUMLINK newNode = (pNUMLINK)malloc(sizeof(struct node));
        newNode->data = score;
        //newNode->next = NULL;

        newNode->next = h->next;
        h->next = newNode;
    }
}
void outLINK(pNUMLINK h) {
    int i = 0;
    pNUMLINK temp = h->next;
    while (temp != NULL) {
        if (i % 10 == 0)
            printf("\n");
        printf("%6d", temp->data);
        temp = temp->next;
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
    p->next = h->next;
    h->next = p;

}
int main() {
    pNUMLINK h = NULL;
    INTEGER key;
    printf("你好");
    createLink(h);
    outLINK(h);
    printf("\n输入要在头插入的数据：");
    scanf_s("%d", &key);
    insertnode(h, key);
    outLINK(h);
    printf("\n");
    system("pause");
    return 0;
}