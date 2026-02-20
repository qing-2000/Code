#include<iostream>
using namespace std;

int grid[4][4] = { 0 };
int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
long long total = 0;

void dfs(int x, int y, int step) {
    if (x < 0 || x >= 4 || y < 0 || y >= 4) return;
    if (grid[x][y]) return;

    grid[x][y] = 1;

    if (step == 15) {  // 已经放置16节（从0开始计数）
        total++;
        grid[x][y] = 0;
        return;
    }

    for (int i = 0; i < 4; i++) {
        dfs(x + dir[i][0], y + dir[i][1], step + 1);
    }

    grid[x][y] = 0;
}

int main() {
    // 利用对称性只需计算三种情况：
    // 1. 角落点（如(0,0)）结果×4
    // 2. 边缘非角落点（如(0,1)）结果×8
    // 3. 中心点（如(1,1)）结果×4

    // 计算角落点
    dfs(0, 0, 0);
    long long corner = total * 4;
    total = 0;

    // 计算边缘点
    dfs(0, 1, 0);
    long long edge = total * 8;
    total = 0;

    // 计算中心点
    dfs(1, 1, 0);
    long long center = total * 4;

    cout << "总方案数: " << corner + edge + center << endl;
    return 0;
}