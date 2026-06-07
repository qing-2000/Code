#include<iostream>
using namespace std;

typedef struct node {
    int data;
    struct node* lch;
    struct node* rch;
} Node;

void init(Node** t) {
    *t = (Node*)malloc(sizeof(Node));  // 分配内存
    (*t)->data = 0;  // 初始化数据
    (*t)->lch = NULL;  // 左子树为空
    (*t)->rch = NULL;  // 右子树为空
}

// 创建树节点
void Create(Node** t, int e, int maxDepth, int depth = 0) {
    if (e == -1 || depth >= maxDepth) {  // 增加终止条件，避免无限递归
        *t = NULL;  // 如果值为-1，表示该节点为空
        return;
    }

    *t = (Node*)malloc(sizeof(Node));  // 分配内存
    (*t)->data = e;  // 设置节点值
    (*t)->lch = NULL;  // 初始化左子树为空
    (*t)->rch = NULL;  // 初始化右子树为空

    // 递归创建左子树和右子树
    int leftData = 2 * e;  // 假设左子树值为 2*e
    int rightData = 2 * e + 1;  // 假设右子树值为 2*e+1

    Create(&(*t)->lch, leftData, maxDepth, depth + 1);  // 创建左子树
    Create(&(*t)->rch, rightData, maxDepth, depth + 1);  // 创建右子树
}

// 打印树的节点
void show(Node* t) {
    if (t) {
        cout << t->data << " ";  // 打印当前节点的值
        show(t->lch);  // 递归打印左子树
        show(t->rch);  // 递归打印右子树
    }
}

int main() {
    Node* t;
    init(&t);  // 初始化树

    int i = 1;  // 根节点从 1 开始
    int maxDepth = 10;  // 设置递归最大深度
    Create(&t, i, maxDepth);  // 创建树

    show(t);  // 打印树
    return 0;
}
