#include <iostream>
using namespace std;
int map[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}};
bool visited[3][3] = {false};
int ans = 0;
void dfs(int x, int y, int target)
{
    if (x < 0 || x >= 3 || y < 0 || y >= 3 || visited[x][y])
        return;
    // 判断终止条件
    visited[x][y] = true;
    if (map[x][y] == target)
    {
        ans += 1;
    }

    else
    {
        for (int i = 0; i < 4; i++)
        {
            int sx = x + dir[i][0];
            int sy = y + dir[i][1];
            // 递归
            if (sx >= 0 && sx < 3 && sy >= 0 && sy < 3)
                dfs(sx,sy,target);
        }
    }
    // 回溯
    visited[x][y] = false;
}
int main()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> map[i][j];
        }
    }
    int x, y, target;
    cin >> x >> y >> target;
    dfs(x,y,target);
    cout << ans;
    return 0;
}