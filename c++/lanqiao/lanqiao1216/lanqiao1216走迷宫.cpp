#include <bits/stdc++.h>
using namespace std;
int xrr[4] = { -1,0,1,0 };
int yrr[4] = { 0,1,0,-1 };
int functiondfs(int x, int y, int a, int b, vector<vector<int>>& G, int ans) {
    if (x < 0 || x >= G.size() || y < 0 || y >= G[0].size())
        return -1;
    if (G[x][y] == 1)return -1;
    if (x == a && y == b)return ans;
    G[x][y] = 1;
    int min_steps = INT_MAX;
    for (int i = 0; i < 4; i++) {
        int newx = x + xrr[i];
        int newy = y + yrr[i];
        int result=functiondfs(newx,newy,a,b,G,ans+1);
        if (result != -1 && result < min_steps) {
            min_steps = result;
        }
    }
    G[x][y] = 0;
    return (min_steps != INT_MAX) ? min_steps : -1;
}
int main()
{
    // 请在此输入您的代码
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, x1, y1, x2, y2;
    cin >> n >> m;
    vector<vector<int>>a(n,vector<int>(m));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;//输入起始位置，终止位置
    x1--; y1--; x2--; y2--;
    int ans;
    ans = functiondfs(x1,y1,x2,y2,a,1);
    cout << ans;
    return 0;
}