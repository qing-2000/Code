#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
typedef int INTEGER;
typedef struct node {
    INTEGER data[N];
} SORT;
int isExistnum(int a[], int k, int t) {
    for (int i = 0; i < k; i++) {
        if (a[i] == t) {
            return 1;
        }
    }
    return 0;
}
void inita(SORT* a) {
    int k = 0, t = 0;
    srand((unsigned int)time(NULL));
    for (; k < N; k++) {
        do {
            t = rand() % 100 + 1;
        } while (isExistnum(a->data, k, t));
        a->data[k] = t;
    }
}
void out(SORT p, INTEGER flag) {
    if (flag) {
        printf("输出已排序的元素值：");
        for (int i = 0; i < N; i++)
        {
            printf("%6d%c", p.data[i], i == 9 ? '\n' : 32);
        }
    }
    else {
        printf("输出未排序的元素值：");
        for (int i = N - 1; i >= 0; i--)
        {
            printf("%6d%c", p.data[i], i == 0 ? '\n' : 32);
        }
    }
}
void sorted(SORT* a) {
    for (int i = N - 1; i >= 0; i--) {
        int max = i;
        for (int j = i - 1; j >= 0; j--) {
            if (a->data[j] > a->data[max]) {
                max = j;
            }
        }
        if (max != i) {
            int temp = a->data[i];
            a->data[i] = a->data[max];
            a->data[max] = temp;
        }
    }
}
int main() {
    char ch;
    while (1) {
        SORT a;
        inita(&a);
        out(a, 0);
        sorted(&a);
        out(a, 1);
        
        printf("是否重新生成新的随机数,给予排序[Y/N]?");
     
        ch = getchar();
        getchar();
        if (ch == 'Y' || ch == 'y') {
            fflush(stdin);
            continue;
        }
        else {
            break;
        }
    }
    return 0;
}