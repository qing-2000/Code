#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int direction[8][2] = {
    {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
    {1, -2}, {1, 2}, {2, -1}, {2, 1}
};

int bfs(int n, int sx, int sy, int ex, int ey) {
    if (sx == ex && sy == ey) return 0;
    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    dist[sx][sy] = 0;
    q.push({sx, sy});
    
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 8; ++i) {
            int nx = x + direction[i][0];
            int ny = y + direction[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                if (nx == ex && ny == ey) return dist[nx][ny];
                q.push({nx, ny});
            }
        }
    }
    return -1; // 不可达
}

int main() {
    int k;
    cin >> k;
    while (k--) {
        int n, sx, sy, ex, ey;
        cin >> n >> sx >> sy >> ex >> ey;
        cout << bfs(n, sx, sy, ex, ey) << endl;
    }
    return 0;
}