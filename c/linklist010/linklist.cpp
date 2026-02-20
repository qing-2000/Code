#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int INTEGER;
typedef struct node {
    INTEGER data;
    struct node* next;
} *pNUMLINK;
INTEGER testscore(pNUMLINK h, int score) {
    pNUMLINK test = h;
    if (test == NULL) {
        return 0;
    }
    while (test->next != h) {
        if (test->data == score) {
            return 1;
        }
        test = test->next;
    }
    if (test->data == score)
    {
        return 1;
    }
    if (test->data == score)
    {
        return 1;
    }
    return 0;
}
void createLink(pNUMLINK* h) {
    int num = 0, size = 0;
    srand((unsigned int)time(NULL));
    while (size < 20) {
        do {
            num = rand() % 100 + 1;
        } while (testscore(*h, num));
        pNUMLINK newnode = (pNUMLINK)malloc(sizeof(struct node));
        newnode->data = num;
        newnode->next = NULL;
        if (*h == NULL) {
            *h = newnode;
            (*h)->next = *h;
        }
        else {
            newnode->next = *h;
            pNUMLINK test = *h;
            while (test->next != *h) {
                test = test->next;
            }
            test->next = newnode;
            *h = newnode;
        }
        size++;
    }
}
void outLink(pNUMLINK h) {
    int size = 0;
    pNUMLINK test = h;
    printf("\n");
    while (test->next != h) {
        printf("%6d", test->data);
        test = test->next;
        size++;
        if (size % 10 == 0) {
            printf("\n");
        }
    }
    printf("%6d", test->data);
}
void insertnode(pNUMLINK* h, INTEGER key) {
    pNUMLINK newnode = (pNUMLINK)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->next = NULL;
    if (*h == NULL)
    {
        *h = newnode;
        (*h)->next = *h;
    }
    else
    {
        newnode->next = *h;
        pNUMLINK test = *h;
        while (test->next != *h)
        {
            test = test->next;
        }
        test->next = newnode;
        *h = newnode;
    }
}
int main() {
    pNUMLINK h = NULL;
    createLink(&h);
    outLink(h);
    printf("\n在头节点之前插入10后：");
    insertnode(&h, 10);
    outLink(h);
    return 0;
}