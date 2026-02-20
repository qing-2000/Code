#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define N 10
typedef int INTEGER;
typedef struct node {
	INTEGER data[N];
}SORT;
int isExistnum(int a[], int k, int t) {
    for (int i = 0; i < k; i++) {
        if (a[i] == t)
            return 1;
    }
    return 0;
}
SORT inita(SORT &t) {
    srand((unsigned)time(NULL));
    int temp;
    for (int i = 0; i < N; i++) {
        do {
            temp = rand() % 101;
        } while (isExistnum(t.data, i, temp));
        t.data[i] = temp;
    }
    return t;
}
void sorted(SORT& t) {
    int i = N-1, j;
    for (i; i >= 0; i--) {
        for (j = i-1; j >= 0; j--) {
            if (t.data[i] > t.data[j])
            {
                int temp = t.data[j];
                t.data[j] = t.data[i];
                t.data[i] = temp;
            }
        }
    }
}
void out(SORT p, INTEGER flag) {
    if (flag == 0)
        printf("\n未排序的元素值：");
    else
        printf("\n已排序的元素值：");
    for (int i = 0; i < N; i++) {
        printf("%6d", p.data[i]);
    }
}
int main() {
    char ch;
    SORT t;
    int flag = 1;
    while (flag) {
        system("cls");
        inita(t);
        out(t, 0);
        sorted(t);
        out(t,1);
        printf("\n是否重新生成新的随机数，给予排序[Y/N]?:");
        ch = toupper(getchar());
        while (getchar() != '\n');
        if (ch != 'Y')
            flag=0;
    }
    return 0;
}