//top为下一个索引,从top-1开始
#include<bits/stdc++.h>
using namespace std;
#define Maxsize 100
typedef struct status {
	int top;
	int base;
	int data[Maxsize];
}SqStatus;
void InitStack(SqStatus* S) {// 构造一个空栈
	S->base = 0;
	S->top = S->base;
}
void push(SqStatus* S,int element) {
	if ( S->top < Maxsize) {
		S->data[S->top] = element;
		S->top++;
	}
	else {
		cout << "栈已满" << endl;
	}
}
void out(SqStatus* S) {
	while (S->top-1 > -1) {
		if (S->top < 0) {
			S->top = 0;
			cout << "栈已空" << endl;
			break;
		}
		cout << S->data[S->top-1] << " ";
		S->top--;
		
	}
}
int main() {
	SqStatus s;
	InitStack(&s);
	int i = 0,e=0;
	while (i < 11) {
		push(&s, i);
		i++;
	}
	out(&s);
	
	return 0;
}