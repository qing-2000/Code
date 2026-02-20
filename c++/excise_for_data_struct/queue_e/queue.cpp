//顺序表实现队列（感觉就是数组）不能释放空间，多用循环队列；
//链表实现队列可释放空间
#include<iostream>
using namespace std;
#define Maxsize 100
typedef struct que {
	int arr[Maxsize],rear,front;
	/*struct que* rear;
	struct que* front;*/

}Queue;
void init(Queue* q) {
	q->rear = -1;
	q->front = -1;
}
void push(Queue* q,int e) {
	if (q->rear == Maxsize - 1)return;
	if (q->front == q->rear && q->front == -1) {
		q->front++; 
		q->rear++;
		q->arr[q->rear] = e;
		q->rear++;
	}
	else {
		q->arr[q->rear] = e;
		q->rear++;
	}
}
void pop(Queue* q) {
	for (int i = q->front; i < q->rear;i++) {
		cout << q->arr[i] << " ";
	}
}
int main() {
	Queue q;
	init(&q);
	int i = 0;
	while (i < 10) {
		push(&q,i);
		i++;
	}
	pop(&q);
	return 0;
}