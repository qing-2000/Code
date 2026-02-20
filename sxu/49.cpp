#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
vector<vector<int>> h;
vector<vector<int>> dp;
int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int dfs(int x, int y) {
    if (dp[x][y] != 0) return dp[x][y];
    int maxlen = 1;
    for (auto& d : dirs) {
        int nx = x + d[0], ny = y + d[1];
        if (nx >= 0 && nx < R && ny >= 0 && ny < C && h[nx][ny] < h[x][y]) {
            maxlen = max(maxlen, dfs(nx, ny) + 1);
        }
    }
    dp[x][y] = maxlen;
    return maxlen;
}

int main() {
    cin >> R >> C;
    h.resize(R, vector<int>(C));
    dp.resize(R, vector<int>(C, 0));
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> h[i][j];
    int ans = 0;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            ans = max(ans, dfs(i, j));
    cout << ans << endl;
    return 0;
}