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
}/*
void createLink(pNUMLINK& h) {
	int i = 0, score;
	pNUMLINK tail = NULL, p;
	h = (pNUMLINK)malloc(sizeof(node));
	h->data = rand() % 21;
	h->next = NULL;
	tail = h;
	while (i < 19) {
		score = rand() % 21;
		while (testscore(h, score) == 0) {
			p = (pNUMLINK)malloc(sizeof(node));
			p->next = NULL;
			p->data = score;
			tail->next = p;
			tail = p;
		}
	}
}*/
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
            pNUMLINK temp = h;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
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
    p= (pNUMLINK)malloc(sizeof(node));
    if (!p) {  // 检查malloc是否成功
        printf("Memory allocation error.\n");
        exit(1);  // 如果内存分配失败，退出程序
    }
    p->data = key;
    p->next = NULL;
	
	while (temp != NULL && temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = p;
}
int main() {
	pNUMLINK h = NULL;
	INTEGER key;
	printf("你好");
	createLink(h);
	outLINK(h);
	printf("\n输入要在尾插入的数据：");
	scanf_s("%d", &key);
	insertnode(h, key);
	outLINK(h);
    printf("\n");
    system("pause");
	return 0;
}

/*
// ⑴ 数据结构定义
typedef int INTEGER;
typedef struct node {
    INTEGER data;
    struct node* next;
} *pNUMLINK;

// ⑵ 定义函数原型
INTEGER testscore(pNUMLINK h, INTEGER score);
void createLink(pNUMLINK& h);
void outLink(pNUMLINK h);
void insertNode(pNUMLINK& h, INTEGER key);

int main() {
    srand(time(NULL));
    pNUMLINK h = NULL;

    // ⑹ 主函数操作
    // ① 相关变量定义并初始化
    createLink(h);  // ② 调用函数createLink(h) 建立链表

    outLink(h);     // ③ 调用函数outLink(h) 输出链表

    INTEGER key = rand() % 100 + 1;
    while (testscore(h, key)) key = rand() % 100 + 1; // 确保key不在链表中
    insertNode(h, key); // ④ 调用函数insertNode(h, key) 插入新节点

    outLink(h);     // ⑤ 调用函数outLink(h) 再次输出链表

    return 0;
}

// ⑵ 自定义测试函数
INTEGER testscore(pNUMLINK h, INTEGER score) {
    while (h != NULL) {
        if (h->data == score) return 1;
        h = h->next;
    }
    return 0;
}

// ⑶ 自定义创建链表函数
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
            pNUMLINK temp = h;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

// ⑷ 自定义输出链表函数
void outLink(pNUMLINK h) {
    int count = 0;
    while (h != NULL) {
        printf("%6d", h->data);
        count++;
        if (count % 10 == 0) printf("\n");
        h = h->next;
    }
}

// ⑸ 自定义插入节点函数
void insertNode(pNUMLINK& h, INTEGER key) {
    pNUMLINK newNode = (pNUMLINK)malloc(sizeof(struct node));
    newNode->data = key;
    newNode->next = NULL;

    pNUMLINK temp = h;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}*/