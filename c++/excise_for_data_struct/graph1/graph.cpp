//图论 --创建基础固定大小的图
//求取每个顶点的--出度--和--入度--；
#include<iostream>
#include<vector>
using namespace std;
typedef struct graph {
	char v[4];
	int edg[4][4];
	
}G;
void init(G *g) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			(*g).v[i] = 'A' + i;
			(*g).edg[i][j] = 0;
		}
	}
}
void imputedge(G* g,char a,char b) {//输入点与点的关系
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((*g).v[i] == a && (*g).v[j] == b)(*g).edg[i][j] = 1;
		}
	}
}
int main() {
	G g;
	init(&g);
	char v,x,y;
	int a, b,infiltration,out_degree;
	vector<pair<int, int>>arr(4);
	for (int i = 0; i < 4; i++) {
		cin >> x >> y;
		imputedge(&g,x,y);
	}
	cout << "  ";  // 打印矩阵左上角的位置
	for (int i = 0; i < 4; i++) {
		cout << g.v[i] << " ";  // 打印列的顶点
	}
	cout << endl;
	for (int i = 0; i < 4; i++) {
		infiltration=0, out_degree = 0;//出度，入度
		cout << g.v[i] << " ";//打印行的顶点
		for (int j = 0; j < 4; j++) {
			out_degree += g.edg[i][j];//行出度和
			infiltration += g.edg[j][i];  // 列入度累加(及--行列反转！！！！--)
			cout << g.edg[i][j]<<" ";
			//if (j == 3)cout << endl;//换行
		}
		cout << "| 出度: " << out_degree << " 入度: " << infiltration << endl;

		// 存储出度和入度
		arr[i] = make_pair(out_degree, infiltration);
	}

	return 0;
}