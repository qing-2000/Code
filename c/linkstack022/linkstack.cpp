#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 10
typedef int INTEGER;
struct node {
	INTEGER data;
	struct node* next;
};
typedef struct stack {
	struct node* head;
	struct node* top;
}*pLinkSTACK;
void initstack(pLinkSTACK& h) {
	h = (pLinkSTACK)malloc(sizeof(stack));
	node* temp = (node*)malloc(sizeof(node));
	temp->data = 0;
	temp->next = NULL;
	h->head = temp;
	h->top = temp;
}

INTEGER getinvalue() {
	int i;
	printf("输入要转化为16进制的10进制数(>=155)：");
	do {
		//scanf_s("值小于155，重新输入：%d", &i);
		scanf_s("%d", &i);
		if (i < 155) {
            //system("cls"); // 清除屏幕
            printf("\n值小于155，重新输入: ");
        }
	} while (i < 155);
	//i = scanf("%d", &i);
	return i;
}
void push(pLinkSTACK& h, INTEGER key) {
	int i, j = key, m = 0, arry[MAX] = {};
	node* current=h->head;
	while (j != 0) {
		i = j % 16;
		j /= 16;
		node* temp = (node*)malloc(sizeof(node));
		if (i > 9)
			i += 55;
		else if (0 < i && i < 10)
			i += 48;
		temp->data = i;
		temp->next = current->next;
		current->next = temp;
	}
	h->top = current;
}
INTEGER isEmpty(pLinkSTACK& h) {
	if (h->head->next == NULL)
		return 1;
	return 0;
}
void pupStack(pLinkSTACK& h) {
	if (isEmpty(h) == 1)
		return;
	node* temp = h->top;
	while (temp != NULL) {	
	printf("%c",temp->data);
	temp=temp->next;
	}
}

int main() {
	pLinkSTACK h;
	INTEGER key;
	initstack(h);
	int flag = 1;
	while(flag){
		
		system("cls");
		fflush(stdin);
		key = getinvalue();
		push(h, key);
		pupStack(h);
		getchar();
		
		printf("\n是否计算其他的16进制[Y/N]：");
		char ch = toupper(getchar());
		if ( ch!= 'Y')
		{
			fflush(stdin);
			flag = 0; 
		}
		system("cls");
	}
	system("pause");
	return 0;
}
