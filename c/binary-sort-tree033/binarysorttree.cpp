#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
typedef struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
}BinTreeNode,*pBinTree;
pBinTree binTreeCreate(BinTreeNode** T, int data) {
	if ((*T) == NULL) {
		*T = (pBinTree)malloc(sizeof(BiTNode));
		(*T)->data = data;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
	}
	else {
		if (data==(*T)->data) {
			return *T;
	}
		else if (data > (*T)->data) {
			return binTreeCreate(&(*T)->rchild, data);
		}
		else {
			return binTreeCreate(&(*T)->lchild, data);
		}
	}
	//printf("创建成功\n");
	return *T;
}
void mindorder(pBinTree T) {
	if (T) {
		mindorder(T->lchild);
		printf("%3d", T->data);
		mindorder(T->rchild);
	}
}
void lastorder(pBinTree T) {
	if (T) {
		lastorder(T->lchild);
		lastorder(T->rchild);
		printf("%3d", T->data);
	}
}
int leafsum(pBinTree T) {
	int count = 0,m,n;
	if (T) {
		if ((T->lchild == NULL) && (T->rchild == NULL))
			count++;
		m = leafsum(T->lchild);
		count += m;
		n = leafsum(T->rchild);
		count += n;
	}
	return count;
}
int hightTree(pBinTree T) {
	int h = 0,lh,rh;
	if (T) {
		lh = hightTree(T->lchild);
		rh = hightTree(T->rchild);
		h = (lh > rh ? lh:rh )+ 1;
	}
	return h;
}
int main() {
	pBinTree T=NULL;
	//int data;
	int a[MAX] = { 32,10,24,17,31,29,46,40,63,49 };
	for (int i = 0; i < 10; i++) {
		//data = a[i];
		binTreeCreate(&T, a[i]);
	}
	printf("\n二叉树中序遍历：");
	mindorder(T);
	printf("\n二叉树后序遍历:");
	lastorder(T);
	printf("\n叶子节点数：%d", leafsum(T));
	
	printf("\n树的高度：%d", hightTree(T));
	
	return 0;
}
