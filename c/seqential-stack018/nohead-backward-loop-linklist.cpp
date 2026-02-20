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

	pNUMLINK temp = h;
	if (temp == NULL) {
		return 0;
	}
	while (temp->next != h) {
		if (temp->data == score) {
			return 1;
		}
		temp = temp->next;
		}
	if (temp->data == score) {
		return 1;
	}
	return 0;
}
void createLink(pNUMLINK &h) {
	srand(time(NULL));
	
	for (int i = 0; i < 20; i++) {
		INTEGER key;
		pNUMLINK last = h;
		do {
			key = rand() % 100 + 1;
		} while (testscore(h, key));
		pNUMLINK newNode = (pNUMLINK)malloc(sizeof(node));
		newNode->data = key;
		newNode->next = NULL;

		if (h == NULL) { // 如果链表为空，新节点既是头也是尾
			h = newNode;
			h->next = h;
			if (h == NULL)
				printf("ERROR");                                                       
		}
		else {
			//pNUMLINK last = h;
			while (last->next != h) {
				last = last->next;
		    }
		    
			newNode->next = last->next;
			last->next = newNode;
		}
	}
	printf("创建成功");
}
void outLINK(pNUMLINK h) {
	int i = 0;
	pNUMLINK temp = h;
	do {
		if (i % 10 == 0)
			printf("\n");
		printf("%6d", temp->data);
		temp = temp->next;
		i++;
	} while (temp != h);
}
void insertnode(pNUMLINK &h, INTEGER key) {
	pNUMLINK temp = h, p;
	p = (pNUMLINK)malloc(sizeof(node));
	if (!p) {  // 检查malloc是否成功
		printf("Memory allocation error.\n");
		exit(1);  // 如果内存分配失败，退出程序
	}
	p->data = key;
	while(temp->next!=h){
		temp = temp->next;
	}
	p->next = temp->next;
	temp->next = p;
	h = p;
}
int main() {
	pNUMLINK h = NULL;
	INTEGER key;
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
