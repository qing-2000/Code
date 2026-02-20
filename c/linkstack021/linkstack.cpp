/**/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
typedef int INTEGER;
struct node;
struct node {
	INTEGER data;
	struct node* next;
};
typedef struct stack {
	struct node* top;
	struct node* head;
}*pLinkSTACK;
void initstack(pLinkSTACK& h) {
	h = (pLinkSTACK)malloc(sizeof(stack));
	h->head = (node*)malloc(sizeof(node));
	h->head->data = 0;
	h->head->next = NULL;
	h->top= h->head;
}
INTEGER getinvalue() {
	int i;
	printf("输入要转化为8进制的10进制数[>155]：");
	do {
		if (scanf_s("%d", &i) != 1) {  // 防止输入格式错误
			fprintf(stderr, "Invalid input format.\n");
			exit(EXIT_FAILURE);
		}
	} while (i < 155);
	return i;
}

void push(pLinkSTACK& h, INTEGER key) {
	int i = key, j, arry[MAX] = {},m=0;
	node* current = h->head;
	while (i != 0) {
		j = i % 8;
		i /=  8;
		arry[m] = j;
		m++;
	}
	for (m; m != 0; m--) {
		node* p = (node*)malloc(sizeof(node));
		p->data = arry[m-1];
		p->next = current->next;
		current->next = p;
		current = p;
	}
	h->top = current;
	
}

INTEGER isEmpty(pLinkSTACK& h) {
	if (h->top == NULL)
		return 1;
	return 0;
}
void popStack(pLinkSTACK& h) {
	if (isEmpty(h) == 1)
		return;
	node* temp = h->head->next;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main() {
	int i;
	pLinkSTACK h;
	initstack(h);
	i=getinvalue();
	push(h, i);
	popStack(h);
}