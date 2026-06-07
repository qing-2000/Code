/*
一天Extense在森林里探险的时候不小心走入了一个迷宫，迷宫可以看成是由n * n的格点组成，每个格点只有2种状态，.和#，前者表示可以通行后者表示不能通行。同时当Extense处在某个格点时，他只能移动到东南西北(或者说上下左右)四个方向之一的相邻格点上，Extense想要从点A走到点B，问在不走出迷宫的情况下能不能办到。如果起点或者终点有一个不能通行(为#)，则看成无法办到。
输入
第1行是测试数据的组数k，后面跟着k组输入。每组测试数据的第1行是一个正整数n (1 <= n <= 100)，表示迷宫的规模是n * n的。接下来是一个n * n的矩阵，矩阵中的元素为.或者#。再接下来一行是4个整数ha, la, hb, lb，描述A处在第ha行, 第la列，B处在第hb行, 第lb列。注意到ha, la, hb, lb全部是从0开始计数的。
输出
k行，每行输出对应一个输入。能办到则输出“YES”，否则输出“NO”。
*/
#include <bits/stdc++.h>
using namespace std;
// 方向数组
int dir[4][2]{
    {0, -1},
    {-1, 0},
    {0, 1},
    {1, 0}};
int step = 0, sx, sy, ex, ey, tempx, tempy;

int dfs(vector<vector<char>> &a,vector<vector<bool>> visited,int sx, int sy)
{
    // 边界判断
    if (sx < 0 || sx > a.size() || sy < 0 || sy > a[0].size())
        return;
    if (a[sx][sy] == '#')
    {
        // 不可行，加入已访问，回溯
        visited[sx][sy] == true;
        return;
    }
    // 抵达判断
    if (sx == ex && sy == ey)
        return step;
    // 是否访问过判断
    if (visited[sx][sy])
        return;
    // 该点可行判断
    if (a[sx][sy] == '*')
    {
        // 可行，步长加1，加入已访问，继续dfs
        step += 1;
        visited[sx][sy] == true;
    }

    // dsf
    for (int i = 0; i < 4; i++)
    {
        tempx = sx + dir[i][0];
        tempy = sy + dir[i][1];
        dfs(a,visited,tempx,tempy);
        // 回溯
        step -= 1;
    }
    return -1;
}
int main()
{
    int k, n;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> n;
        vector<vector<char>> a(n,vector<char>(n));
        // 状态数组
        vector<vector<bool>> visited(n,vector<bool>(n));
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < n; l++)
                cin >> a[j][l];
        }
        cin >> sx >> sy >> ex >> ey;
        if (dfs(a,visited,sx,sy) > 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        a.clear();
        visited.clear();
    }
    return 0;
}