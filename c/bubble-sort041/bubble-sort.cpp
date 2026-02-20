#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 10
typedef int INTEGER;
typedef struct node {
	INTEGER data[N];
}SORT;
int isExistnum(int a[],int k,int t) {
	for (int i = 0; i <=k-1; i ++) {
		if (a[i] == t)
			return 1;
	}
	return 0;
}
void init(SORT& t) {
	srand((unsigned int)time(NULL));
	int temp;
	for (int i = 0; i < N; i++) {
		do {
			temp = rand() % 101;
		}while(isExistnum(t.data, i, temp));
		t.data[i] = temp;
	}
}
void out(SORT& a, INTEGER flag) {
	if (flag == 0) {
		printf("未排序的序列：");
		for (int i = 0; i < N; i++) {
			printf("%6d", a.data[i]);
		}
		printf("\n");
	}else if(flag==1){
		printf("排序后的序列：");
		for (int i = 0; i < N; i++) {
			printf("%6d", a.data[i]);
		}
		printf("\n");
	}
}

void sorted(SORT& t) {
	int temp;
	for (int i= 0; i < 9; i++) {
		for (int j = 0; j < 10 -i-1; j++) {
			if (t.data[j] < t.data[j+1]) {
				temp = t.data[j];
				t.data[j] = t.data[j+1];
				t.data[j + 1] = temp;
			}
		}
	}
}
int main() {
	SORT a;
	//int flag=1;
	char choice;
	while (1) {
		system("cls");
		
		init(a);
		out(a, 0);
		sorted(a);
		out(a, 1);
		printf("是否重新生成新的随机数，给予排序？[Y/N]:");
		choice=toupper(getchar());
		if(choice != 'Y')
        break;
		int c;
        while ((c = getchar()) != '\n' && c != EOF);
        fflush(stdin);
	}
	return 0;
}
