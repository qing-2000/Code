#include<iostream>
using namespace std;
typedef struct node {
	int data;
	struct node* lch;
	struct node* rch;
}Node;
void init(Node** t) {
	*t = (Node*)malloc(sizeof(Node));
	*t = NULL;
}
void Create(Node** t,int a[],int& i) {
	int val = a[i++];
	if (val == -1) {
		*t = NULL;
		return;
	}
	else {
		*t = (Node*)malloc(sizeof(Node));
		(*t)->data = val;
		Create(&(*t)->lch, a,i);
		Create(&(*t)->rch, a,i);
	}

}
void preshow(Node* t) {
	if (t) {
		cout << t->data << " ";
		preshow(t->lch);
		preshow(t->rch);
	}
}
void midshow(Node* t) {
	if (t) {
		midshow(t->lch);
		cout << t->data << " ";
		midshow(t->rch);
	}
}
void lastshow(Node* t) {
	if (t) {
		lastshow(t->lch);
		
		lastshow(t->rch);
		cout << t->data << " ";
	}
}
int leafsum(Node* t) {
	int sum = 0,l,r;
	if (t) {
		if (t->lch == NULL && t->rch == NULL) {
			sum++;
		}
		l=leafsum(t->lch);
		sum += l;
		r=leafsum(t->rch);
		sum += r;
	}
	return sum;
}
int depth(Node* t) {
	int dep = 0,l,r;
	if (t==NULL) {
		dep = 0;
	}else{
		l = depth(t->lch);
		r = depth(t->rch);
		dep = 1 + (l > r ? l : r);
	}
	return dep;
}
int sumnode(Node* t) {
	int sum = 0, l, r;
	if (t) {
		sum++;
		l = sumnode(t->lch);
		sum += l;
		r = sumnode(t->rch);
		sum += r;
	}
	return sum;
}
int main() {
	Node* t;
	init(&t);
	int i = 0, a[7] = {1,2,-1,-1,3,-1,-1};
	int j = 0;
	Create(&t, a, j);
	cout << "前序遍历：";
	preshow(t);
	cout << endl;
	cout << "中序遍历：";
	midshow(t);
	cout << endl;
	cout << "后序遍历：";
	lastshow(t);
	cout << endl;
	int sum = leafsum(t);
	cout << "二叉树叶子节点数： " << sum << endl;
	int dep = depth(t);
	cout << "二叉树深度：" << dep << endl;
	int sn = sumnode(t);
	cout << "二叉树的节点总数：" << sn << endl;
	return 0;
}

