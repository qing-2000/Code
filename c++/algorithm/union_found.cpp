#include <vector>
#include <iostream>

class UnionFind {
private:
    std::vector<int> parent;  // 存储每个元素的父节点
    std::vector<int> rank;    // 存储树的秩（高度）
    int count;                // 连通分量数量

public:
    // 构造函数，初始化n个元素
    UnionFind(int n) : count(n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;  // 初始时每个元素的父节点是自己
        }
    }

    // 查找元素p的根节点，带路径压缩
    int find(int p) {
        // 路径压缩：将查找路径上的所有节点直接连接到根节点
        if (parent[p] != p) {
            parent[p] = find(parent[p]);
        }
        return parent[p];
    }

    // 合并元素p和q所在的集合
    void unionSet(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        
        if (rootP == rootQ) return;  // 已经在同一个集合中
        
        // 按秩合并：将秩较小的树连接到秩较大的树
        if (rank[rootP] > rank[rootQ]) {
            parent[rootQ] = rootP;
        } else if (rank[rootP] < rank[rootQ]) {
            parent[rootP] = rootQ;
        } else {
            parent[rootQ] = rootP;
            rank[rootP]++;  // 秩相等时，合并后秩增加1
        }
        count--;  // 连通分量数量减1
    }

    // 判断元素p和q是否连通
    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    // 返回连通分量的数量
    int getCount() const {
        return count;
    }
};

// 测试示例
int main() {
    UnionFind uf(10);  // 创建包含10个元素的并查集
    
    // 进行一些合并操作
    uf.unionSet(1, 2);
    uf.unionSet(2, 3);
    uf.unionSet(4, 5);
    uf.unionSet(5, 6);
    uf.unionSet(1, 6);  // 这会连接两个集合
    
    // 测试连通性
    std::cout << "1和3是否连通: " << (uf.connected(1, 3) ? "是" : "否") << std::endl;
    std::cout << "1和4是否连通: " << (uf.connected(1, 4) ? "是" : "否") << std::endl;
    std::cout << "7和8是否连通: " << (uf.connected(7, 8) ? "是" : "否") << std::endl;
    
    // 连通分量数量
    std::cout << "连通分量数量: " << uf.getCount() << std::endl;
    
    return 0;
}