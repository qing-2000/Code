#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>
//首先定义结构体
typedef struct node {
	int data;//值
	struct node* lch, * rch;
}BinSortTreeNode, * pBinSortTree;
//其次，定义全局变量root，p,q;
node* root = NULL, * p, * q;
//数组赋值
void initarray(int* a) {
	int t;
	//伪随机数
	srand((unsigned int)time(NULL));
	for (int k = 0; k < 10; k++) {
		a[k] = rand() % 100 + 1;
	}
}
//创建二叉树（非递归）
void CreatSortBinTree(int* a) {
	node* s, * p, * q=NULL;
	for (int i = 0; i < 10; i++) {
		// 分配节点，初始化数据与左右子树
		s = (pBinSortTree)calloc(1, sizeof(BinSortTreeNode));
		s->data = a[i];
		s->rch = s->lch = NULL;
		// 判断根节点是否为空
		if (root == NULL) root = s;
		else {
			p = root;
			while (p != NULL) { // while循环确定左右子树
				q = p;
				if (s->data < p->data) // 新节点的值小于根节点，指向左子树
					p = p->lch;
				else
					p = p->rch;
			}
			// 赋值
			if (s->data < q->data)
				q->lch = s;
			else
				q->rch = s;
		}
	}
}
//中序输出
void inorderprint(node* t) {
	if (t != NULL) {
		inorderprint(t->lch);
		printf("%5d", t->data);
		inorderprint(t->rch);
	}
}
//交换左右子树
void changetree(node* t) {
	node* r;
	if (t != NULL) {
		r = t->lch;
		t->lch = t->rch;
		t->rch = r;
		changetree(t->lch);
		changetree(t->rch);
	}
}
//比较输入元素与树中的数据
void comPare(node* t, int k) {
	int flag = 0;
	p = NULL;
	q = t;
	while (q != NULL) {
		if (q->data == k) {
			printf("发现节点，其数据：%d\n", q->data);
			flag = 1;
			break;
		}
		else if (k < q->data) {
			p = q;
			q = q->lch;
		}
		else {
			p = q;
			q = q->rch;
		}
	}
	if (flag == 0)
		printf("\n没有在树中找到该节点。");
}
//插入节点
void Insernode(node* t, int k) {
	node* r;
	comPare(root, k);
	if (q == NULL) {
		r = (node*)malloc(sizeof(node));
		r->data = k;
		r->lch = r->rch = NULL;
		if (root == NULL) root = r;
		else if (k < p->data)
			p->lch = r;
		else
			p->rch = r;
	}
}
//输出树的构成元素
void printElem(int a[]) {
	for (int i = 0; i < 10; i++) {
		printf("%d\t", a[i]);
	}
}
int main() {
	int* a = new int[10];
	int n;
	initarray(a);
	printf("树中的元素：");
	printElem(a);
	CreatSortBinTree(a);
	printf("\n中序遍历的顺序：");
	inorderprint(root);
	printf("\n交换左右子树的中序遍历顺序：");
	changetree(root);
	inorderprint(root);
	printf("\n输入要查找的数据：");
	scanf_s("%d", &n);
	comPare(root, n);
	free(a);
	return 0;
}