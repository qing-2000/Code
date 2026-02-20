#include<iostream>
using namespace std;
struct node {
	int a, b;

};
int arr[4][4] = { 0 }, res = 0;
struct node brr[4] = { {1,0},{0,1},{-1,0},{0,-1} };
void dfs(int x,int y,int count) {
	
	if (x > 3 || x < 0 || y>3 || y < 0)return;//越界返回
	if (arr[x][y] == 1)return;// 访问过了返回

	arr[x][y] = 1;//访问该点
	count++;
	if (count == 16) {
		res++;//成功走完次数+1
		arr[x][y] = 0;//重置前一点状态
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int h_c = x + brr[i].a, y_c = y + brr[i].b;//向四个方向访问
		dfs(h_c, y_c, count);
	}
	arr[x][y] = 0;//重置状态
}
int main() {
	
	for (int i = 0; i < 4;i++) {
		for (int j = 0; j < 4; j++) {
			dfs(i, j, 0);
	}
	}
	cout << res;
	return 0;
}