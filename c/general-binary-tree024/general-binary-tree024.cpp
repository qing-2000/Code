#include<stdio.h>
#include<stdlib.h>
#include<String.h>
typedef struct BiTNode {
    char data;
    struct BiTNode* lchild, * rchild;
} BinTreeNode, * pBinTree;
pBinTree binTreeCreate(pBinTree* T) {
    char ch;
    scanf_s(" %c", &ch);
    if (ch == '#') {
        *T = NULL;
    }
    else {
        *T = (pBinTree)malloc(sizeof(struct BiTNode));
        if (*T == NULL) {
            printf("内存分配失败！\n");
            return NULL;
        }
        (*T)->data = ch;
        binTreeCreate(&(*T)->lchild);
        binTreeCreate(&(*T)->rchild);
    }
    return *T;
}
void midorder(pBinTree T) {
    if (T != NULL) {
        midorder(T->lchild);
        printf("%c", T->data);
        midorder(T->rchild);
    }
}
void lastorder(pBinTree T) {
    if (T != NULL) {
        lastorder(T->lchild);
        lastorder(T->rchild);
        printf("%c", T->data);
    }
}
int leafsum(pBinTree T) {
    int sum = 0;
    if (T != NULL) {
        if (!T->lchild && !T->rchild) {
            return 1;
        }
    }
    else {
        return 0;
    }
    return leafsum(T->lchild) + leafsum(T->rchild);
}
int highTree(pBinTree T) {
    int dep = 0;
    if (T == NULL) {
        return 0;
    }
    int depl = highTree(T->lchild);
    int depr = highTree(T->rchild);
    return 1 + (depl >= depr ? depl : depr);
}
int main() {
    pBinTree T = NULL;
    printf("请输入前序遍历[#号代表空节点]例：AB##C##:");
    T = binTreeCreate(&T);
    printf("二叉树的中序遍历:");
    midorder(T);
    printf("\n二叉树的后序遍历:");
    lastorder(T);
    int sum = leafsum(T);
    printf("\n叶子节点有%d个\n", sum);
    int dep = highTree(T);
    printf("二叉树的高度为%d\n", dep);
    return 0;
}