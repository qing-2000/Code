#include <iostream>
#include <vector>
using namespace std;

int n;  // 所需方阵的大小
int row[20], col[20];  // 每行/列需要访问的次数
int grid[20][20] = { 0 };  // 记录访问状态
vector<int> s;  // 栈，记录路径
int dx[] = { 0, 0, 1,-1 };
int dy[] = { 1,-1, 0, 0 };
// 检查当前格子是否符合条件--允许访问
bool checktemp(int a, int b) {

    return (row[a] > 0 && col[b] > 0);
   
}
//检查所有是否符合
bool checkall() {
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        x += row[i];
        y += col[i];
    }

    if (x == 0 && y == 0)return true;
    return false;
}

// 深度优先搜索（DFS）
void dfs(int a, int b) {
    if (a < 0 || a >= n || b < 0 || b >= n || grid[a][b] == 1 || !checktemp(a, b)) return;  // 越界或已访问

    grid[a][b] = 1;  // 标记访问
    row[a]--;  // 更新行访问次数
    col[b]--;  // 更新列访问次数
    s.push_back(a * n + b);  // 记录位置

    // 如果到达右下角，并且所有行列访问次数符合要求，则输出路径
    if (a == n - 1 && b == n - 1 && checkall()) {
        for (auto& n : s)cout << n << " ";
        exit(0);  // 输出完路径后结束递归
    }

    // 四个方向的移动

    for (int i = 0; i < 4; i++) {
        int new_a = a + dx[i];
        int new_b = b + dy[i];
        dfs(new_a, new_b);  // 递归访问
    }

    // 回溯
    grid[a][b] = 0;
    s.pop_back();
    row[a]++;  // 恢复行访问次数
    col[b]++;  // 恢复列访问次数
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> col[i];  // 输入列的访问次数
    for (int i = 0; i < n; i++) cin >> row[i];  // 输入行的访问次数

    dfs(0, 0);  // 从(0, 0)开始搜索

    return 0;
}