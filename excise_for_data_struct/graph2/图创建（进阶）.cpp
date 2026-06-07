//通过vector容器实现n*m阶的图
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<char>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];//输入图的顶点


	vector<vector<int>>G(n, vector<int>(m, 0));//图的邻接矩阵


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> G[i][j];//输入图顶点之间的边，0为没有，1为存在
		}
	}
	cout << "  ";//两个空格错位
	for (int i = 0; i < n; i++)cout << v[i] << " ";
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
		for (int j = 0; j < m; j++) {
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}