#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 修改1: 定义节点结构体，存储坐标和距离
struct Node {
    int x, y;
    int dist;
    Node(int _x, int _y, int _dist) : x(_x), y(_y), dist(_dist) {}
};

int dir[4][2] = {
    {-1, 0}, // 上
    {0, -1}, // 左  
    {1, 0},  // 下
    {0, 1}   // 右
};

int map[3][3];
// 修改2: 队列存储节点信息，而不是单纯数值
queue<Node> q;
// 修改3: 使用二维数组记录访问状态
bool visited[3][3] = {false};

bool isInMap(int x, int y) {
    return x >= 0 && x < 3 && y >= 0 && y < 3; // 修改4: 修正边界判断
}

int bfs(int start_val, int target_val) {
    // 步骤1: 寻找起始点
    int start_x = -1, start_y = -1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (map[i][j] == start_val) {
                start_x = i;
                start_y = j;
                break;
            }
        }
        if (start_x != -1) break;
    }
    
    if (start_x == -1) return -1; // 起始点不存在
    
    // 步骤2: BFS初始化
    // 清空访问数组和队列
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            visited[i][j] = false;
            
    while(!q.empty()) q.pop();
    
    // 起点入队并标记
    q.push(Node(start_x, start_y, 0));
    visited[start_x][start_y] = true;
    
    // 步骤3: BFS主循环
    while (!q.empty()) {
        // 步骤3a: 出队当前节点
        Node current = q.front();
        q.pop();
        
        // 步骤3b: 检查是否到达目标
        if (map[current.x][current.y] == target_val) {
            return current.dist;
        }
        
        // 步骤3c: 遍历四个方向的邻居
        for (int i = 0; i < 4; i++) {
            int new_x = current.x + dir[i][0];
            int new_y = current.y + dir[i][1];
            
            // 检查新坐标是否有效且未访问
            if (isInMap(new_x, new_y) && !visited[new_x][new_y]) {
                // 标记为已访问并入队
                visited[new_x][new_y] = true;
                q.push(Node(new_x, new_y, current.dist + 1)); // 修改5: 正确计算距离
            }
        }
    }
    
    return -1; // 未找到目标
}

int main() {
    cout << "输入3x3图矩阵（9个数字）：";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> map[i][j];
        }
    }
    
    cout << "请输入起始位置数值：";
    int start;
    cin >> start;
    cout << "请输入目标位置数值：";
    int end;
    cin >> end;
    
    int result = bfs(start, end);
    if (result >= 0) {
        cout << "最短步数: " << result << endl;
    } else {
        cout << "ERROR: 路径不存在" << endl;
    }
    return 0;
}