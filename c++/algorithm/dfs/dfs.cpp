#include<iostream>
using namespace std;

bool visited[3][3] = {false};
int map[3][3];
int dir[4][2] = {
    {-1, 0},
    {0, -1}, 
    {1, 0},
    {0, 1}
};
int ans = 0;

bool isInMap(int x, int y) {
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

void dfs(int x, int y, int target) {
    // 边界检查和访问检查
    if (!isInMap(x, y) || visited[x][y]) {
        return;
    }
    
    // 标记访问
    visited[x][y] = true;
    
    // 终止条件
    if (map[x][y] == target) {
        ans += 1;
        // 找到目标后也要回溯
        visited[x][y] = false;
        return;
    }
    
    // DFS遍历四个方向
    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        dfs(nx, ny, target);
    }
    
    // 回溯
    visited[x][y] = false;
}

int main() {
    int temp;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> temp;
            map[i][j] = temp;
        }
    }
    
    dfs(0, 0, 9);
    cout << ans;
    return 0;
}