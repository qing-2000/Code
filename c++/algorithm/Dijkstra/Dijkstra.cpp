#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

// Dijkstra算法实现类
class Dijkstra {
private:
    int vertices; // 节点数量
    vector<vector<pair<int, int>>> graph; // 邻接表：graph[u] = {v, weight}

public:
    // 构造函数，初始化节点数量
    Dijkstra(int n) : vertices(n), graph(n) {}

    // 添加边
    void addEdge(int u, int v, int weight) {
        graph[u].push_back({v, weight});
        // 如果是无向图，添加下面这行
        // graph[v].push_back({u, weight});
    }

    // 执行Dijkstra算法
    vector<int> findShortestPath(int start) {
        // 初始化距离数组，所有节点距离设为无穷大
        vector<int> dist(vertices, INT_MAX);
        // 存储前驱节点，用于重建路径
        vector<int> prev(vertices, -1);
        // 优先队列（最小堆）：{距离, 节点}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // 起始节点距离设为0
        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int currentDist = pq.top().first;
            int currentNode = pq.top().second;
            pq.pop();

            // 如果当前距离不是最短距离，跳过
            if (currentDist > dist[currentNode]) {
                continue;
            }

            // 遍历当前节点的所有邻居
            for (auto& neighbor : graph[currentNode]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;
                int newDist = currentDist + weight;

                // 如果找到更短的路径
                if (newDist < dist[nextNode]) {
                    dist[nextNode] = newDist;
                    prev[nextNode] = currentNode;
                    pq.push({newDist, nextNode});
                }
            }
        }

        return dist;
    }

    // 重建从起点到终点的最短路径
    vector<int> reconstructPath(int start, int end, const vector<int>& prev) {
        vector<int> path;
        
        // 从终点回溯到起点
        for (int at = end; at != -1; at = prev[at]) {
            path.push_back(at);
        }
        
        // 反转路径
        reverse(path.begin(), path.end());
        
        // 检查路径是否有效（起点到终点是否连通）
        if (path[0] != start) {
            return {}; // 返回空路径表示不连通
        }
        
        return path;
    }

    // 打印最短路径结果
    void printShortestPaths(int start) {
        vector<int> distances = findShortestPath(start);
        vector<int> prev(vertices, -1);
        
        cout << "从节点 " << start << " 到各节点的最短距离：" << endl;
        for (int i = 0; i < vertices; i++) {
            if (distances[i] == INT_MAX) {
                cout << "节点 " << i << ": 不可达" << endl;
            } else {
                cout << "节点 " << i << ": " << distances[i] << endl;
            }
        }
    }
};

// 测试函数
int main() {
    // 创建一个有6个节点的图
    Dijkstra dijkstra(6);

    // 添加边
    dijkstra.addEdge(0, 1, 4);
    dijkstra.addEdge(0, 2, 2);
    dijkstra.addEdge(1, 2, 1);
    dijkstra.addEdge(1, 3, 5);
    dijkstra.addEdge(2, 3, 8);
    dijkstra.addEdge(2, 4, 10);
    dijkstra.addEdge(3, 4, 2);
    dijkstra.addEdge(3, 5, 6);
    dijkstra.addEdge(4, 5, 3);

    // 计算从节点0开始的最短路径
    dijkstra.printShortestPaths(0);

    cout << "\n=== 另一个测试用例 ===" << endl;

    // 创建无向图测试
    Dijkstra undirectedGraph(5);
    
    // 添加无向图的边（双向）
    undirectedGraph.addEdge(0, 1, 10);
    undirectedGraph.addEdge(0, 3, 5);
    undirectedGraph.addEdge(1, 2, 1);
    undirectedGraph.addEdge(1, 3, 2);
    undirectedGraph.addEdge(2, 4, 4);
    undirectedGraph.addEdge(3, 1, 3);
    undirectedGraph.addEdge(3, 2, 9);
    undirectedGraph.addEdge(3, 4, 2);
    undirectedGraph.addEdge(4, 0, 7);
    undirectedGraph.addEdge(4, 2, 6);

    // 计算从节点0开始的最短路径
    undirectedGraph.printShortestPaths(0);

    return 0;
}