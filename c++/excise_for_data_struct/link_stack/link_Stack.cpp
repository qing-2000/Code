//头节点为栈顶的链栈，头插法
#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct stack{
	int data;
	struct stack* next;
}Stack;
//初始化链栈
void init(Stack** S) {
	*S = (Stack*)malloc(sizeof(Stack));
	(*S)->data = 0;
	(*S)->next = NULL;
}
//创建链栈
void push(Stack* S,int e) {
	if (S->next == NULL) {
		Stack* p = (Stack*)malloc(sizeof(Stack));
		p->data = e;
		p->next = S->next;
		S->next = p;
		p->next = NULL;
	}
	else {
		Stack* p = (Stack*)malloc(sizeof(Stack));
		p->data = e;
		p->next = S->next;
		S->next = p;
	}
	
}
//出栈
void pop(Stack* S) {
	while (1) {
		if (S->next != NULL) {
			Stack* p = S->next;
			cout << p->data << " ";
			S->next = S->next->next;
			free(p);
		}
		else {
			cout << "栈空" << endl;
			break;
		}
	}
}
int main() {
	Stack* S;
	init(&S);
	int i = 0;
	while (i < 11) {
		push(S, i);
		i++;
	}
	pop(S);
	
	
	return 0;
}
