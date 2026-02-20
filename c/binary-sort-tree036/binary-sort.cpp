#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//首先定义结构体
typedef struct BiTNode {
	int data;//值
	struct BiTNode * lch, * rch;
}BinTreeNode, * pBinTree;
//创建二叉树（非递归）
struct BiTNode* root=NULL;
pBinTree binTreeCreate(pBinTree* T, int a[])/*(int* a)*/ {
	BiTNode* s, * p, * q=NULL;
	for (int i = 0; i < 10; i++) {
		// 分配节点，初始化数据与左右子树
		s = (pBinTree)calloc(1, sizeof(BinTreeNode));
		s->data = a[i];
		s->rch = s->lch = NULL;
		if (root == NULL) root = s;
		else {
			p = root;
			while (p != NULL) { 
				q = p;
				if (s->data < p->data) 
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
	return *T;
}
//中序输出
void inorderprint(BiTNode* t) {
	if(t != NULL) {
		inorderprint(t->lch);
		printf("%d\t", t->data);
		inorderprint(t->rch);
	}
}
//交换左右子树
void changetree(BiTNode* t) {
	BiTNode* r;
	if (t != NULL) {
		r = t->lch;
		t->lch = t->rch;
		t->rch = r;
		changetree(t->lch);
		changetree(t->rch);
	}
}

void printElem(int a[]) {
	for (int i = 0; i < 10; i++) {
		printf("%d\t", a[i]);
	}
}
void lastorder(BiTNode *T) {
	if (T!=NULL) {
		lastorder(T->lch);
		lastorder(T->rch);
		printf("%d\t", T->data);
	}
}
int leafsum(pBinTree& T) {
	int count = 0, r, l;
	if (T == NULL)
		return 0;
	else {
		if ((T->lch == NULL) && (T->rch == NULL))
			count++;
		l = leafsum(T->lch);
		count += l;
		r = leafsum(T->rch);
		count += r;
	}
	return count;
}
int dep(pBinTree& T) {
	int d = 0, l, r;
	if (T == NULL)
		return 0;
	else {
		l = dep(T->lch);
		r = dep(T->rch);
		d = (l > r ? l : r )+ 1;
	}
	return d;
}
int nodesum(BiTNode* T) {
	if (T)
		return nodesum(T->lch) + nodesum(T->rch) + 1;
	else
		return 0;
}
int main() {
	BiTNode* T = NULL;
	int a[] = { 53,49,32,10,24,17,31,29,46,40 };
	//printf("树中的元素：");
	//printElem(a);
	binTreeCreate(&T,a);
	printf("\n中序遍历的顺序：");
	inorderprint(root);
	printf("\n后序遍历的顺序：");
	lastorder(root);
	printf("\n叶子节点数：%d", leafsum(root));
	printf("\n深度：%d", dep(root));
	printf("\n总节点：%d", nodesum(root));
	return 0;
}
