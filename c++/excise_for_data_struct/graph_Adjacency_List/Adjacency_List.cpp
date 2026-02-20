//此code记录的是有向图
//初级--邻接表的创建（固定大小）
#include<iostream>
#include<vector>
using namespace std;

//先，创建 边表节点
typedef struct EdgeNode {
	int position;
	struct EdgeNode* next;
}E;
//再，创建 顶点节点
typedef struct VertexNode {
	char data;
	E* first;
}V;
//通过vertex集，创建邻接表
typedef struct {
	V *list;
	int v_num, e_num;//顶点数，边数
}AlGraph;//图的邻接表

//初始化,创建
void initGraph(AlGraph& G, int vertexCount, int edgeCount) {
	G.v_num = vertexCount;
	G.e_num = edgeCount;
	G.list = new V[vertexCount];

	// 初始化每个顶点的边表为空
	for (int i = 0; i < vertexCount; i++) {
		G.list[i].first = nullptr;
		G.list[i].data='A'+i;//从A-A+i的vertex
	}
}
//添加edge
void addEdge(AlGraph G,int start,int end) {
	E* newEdge = new E;
	newEdge->position = end;//当前vertex指向的下一个vertex所在的vertex集索引
	newEdge->next = G.list[start].first;//新节点指向当前节点
	G.list[start].first = newEdge;//更新当前节点
}
// 计算入度和出度
void calculateDegrees(const AlGraph& G, vector<int>& indegree, vector<int>& outdegree) {
	
	indegree.resize(G.v_num, 0);//初始化入度集的vector容器
	
	outdegree.resize(G.v_num, 0);//初始化出度集的vector容器

	// 计算每个顶点的出度和入度
	for (int i = 0; i < G.v_num; i++) {
		E* edge = G.list[i].first;
		while (edge != nullptr) {
			outdegree[i]++;         // 出度增加
			indegree[edge->position]++; // 入度增加
			edge = edge->next;
		}
	}
}
// 打印图的入度和出度
void printDegrees(const vector<int>& indegree, const vector<int>& outdegree,AlGraph G) {
	cout << "Vertex  In-Degree  Out-Degree" << endl;
	for (int i = 0; i < indegree.size(); i++) {
		cout << i << "|" << G.list[i].data << "        " << indegree[i] << "          " << outdegree[i] << endl;
	}
	cout << endl;
}
//遍历邻接表
void printAlGraph(AlGraph &G) {
	for (int i = 0; i < G.v_num; i++) {
		cout << G.list[i].data;
		while(G.list[i].first != nullptr) {
			cout << " -> " << "[" << G.list[i].first->position <<"]"<<G.list[G.list[i].first->position].data; // 输出出边
			G.list[i].first = G.list[i].first->next;
		}
		if(G.list[i].first == nullptr) {
			cout << " -> NULL"; // 没有出边
		}
		cout << endl;
	}
}
int main() {
	AlGraph G;

	int vertexCount = 5; // 顶点数
	int edgeCount = 6;   // 边数

	initGraph(G, vertexCount, edgeCount);

	// 添加一些边（例如：0->1, 0->2, 1->3, 2->3, 3->4）
	addEdge(G, 0, 1);
	addEdge(G, 0, 2);
	addEdge(G, 1, 3);
	addEdge(G, 2, 3);
	addEdge(G, 3, 4);

	vector<int> indegree, outdegree;//出入度
	calculateDegrees(G, indegree, outdegree);//计算出入度
	printDegrees(indegree, outdegree,G);//输出出入度
	printAlGraph(G);//遍历输出邻接表
	return 0;
}