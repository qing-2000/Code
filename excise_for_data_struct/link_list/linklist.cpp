#include<bits/stdc++.h>
using namespace std;
typedef struct node {
	int data;
	node* next;
}Node,*pnode;
Node* h = NULL;
Node* e;
//初始化
void initnode() {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = 0;
	p->next = NULL;
	h = p;
	e = h;
}
//头插法
int i = 1;
void insert_node(int num) {
	while (num) {
		if(h->next==NULL){
			Node* p = (Node*)malloc(sizeof(Node));
			p->data = i;
			p->next = h->next;
			e = p;
			h->next = e;
			e->next = NULL;
		}
		else {
			Node* p = (Node*)malloc(sizeof(Node));
			p->data = i;
			p->next = h->next;
			h->next = p;
		}
		i++;
		num--;
	}
}
//尾插法
void tail_insert(int num) {
	while (num) {
		if (h->next==NULL) {
			Node* p = (Node*)malloc(sizeof(Node));
			p->data = i;
			p->next = NULL;
			e = p;
			h->next = e;
		}
		else {
			Node* p = (Node*)malloc(sizeof(Node));
			p->data = i;
			p->next = NULL;
			e->next=p;
			e = p;
		}
		i++;
		num--;
	}
}
//遍历输出
void show() {
	Node* p = h->next;
	while (p != NULL) {
		cout << p->data;
		p = p->next;
	}
	cout << endl;
}
//删除指定数据
void del_num_node(int target) {
	Node* p = h->next;
	node* q = h;
	while (p) {
		if (p  == e && p->data!=target) {
			cout << "未能在链表中找到该数。" << endl;
			exit(1);
		}
		if (p->data == target)break;
		p = p->next;
		q = q->next;
		
	}
	if (p!= e) {
		q->next = p->next;
		free(p);
	}
	if (p == e) {
		free(p);
		q->next = NULL;
	}

}
//改变指定数据
void cgnum(int num,int target) {
	Node* p = h->next;
	while (p) {
		if (p->data == num) {
			p->data = target;
			break;
		}
		p = p->next;
	}
	if (p == e && p->data != num)cout << "没有找到指定数据。" << endl;
}
int main() {
	int nodenum = 0,num=0,target1=0;
	initnode();
	cout << h->data<<" " << e->data << endl << "输入要创建的链表的大小：";
	cin >> nodenum;
	insert_node(nodenum);//头插法
	show();
	tail_insert(nodenum);//尾插法
	show();
	cout << "输入要改变的数据及改变后的数据：";
	cin >> num >> target1;
	cgnum(num, target1);
	show();
	cout << endl<<"输入链表中要删除的值:";
	int target;
	cin >> target;
	del_num_node(target);
	show();
	return 0;
}