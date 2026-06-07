#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Prim算法实现最小生成树
class PrimMST {
private:
    int V; // 顶点数量
    vector<vector<pair<int, int>>> adj; // 邻接表：{邻居顶点, 权重}

public:
    PrimMST(int vertices) : V(vertices) {
        adj.resize(V);
    }
    
    // 添加无向边
    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
    
    // Prim算法实现
    void primMST() {
        // 用于存储最小权重
        vector<int> key(V, INT_MAX);
        // 用于存储父节点，构建MST
        vector<int> parent(V, -1);
        // 标记顶点是否在MST中
        vector<bool> inMST(V, false);
        
        // 优先队列：{权重, 顶点}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // 从顶点0开始
        key[0] = 0;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            
            // 如果顶点已经在MST中，跳过
            if (inMST[u]) continue;
            
            inMST[u] = true;
            
            // 遍历所有邻居
            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
                // 如果v不在MST中，且找到更小的权重
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }
        
        // 打印最小生成树
        printMST(parent);
    }
    
    // 打印最小生成树
    void printMST(const vector<int>& parent) {
        cout << "最小生成树的边：" << endl;
        int totalWeight = 0;
        
        for (int i = 1; i < V; i++) {
            // 找到边的权重
            int weight = 0;
            for (auto& neighbor : adj[i]) {
                if (neighbor.first == parent[i]) {
                    weight = neighbor.second;
                    break;
                }
            }
            cout << parent[i] << " - " << i << " : " << weight << endl;
            totalWeight += weight;
        }
        
        cout << "最小生成树的总权重: " << totalWeight << endl;
    }
};

// 测试函数
int main() {
    // 创建图
    PrimMST graph(5);
    
    // 添加边
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 4, 9);
    
    // 执行Prim算法
    graph.primMST();
    
    return 0;
}