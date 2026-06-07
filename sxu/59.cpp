/*
地图用一个R×C的字符矩阵来表示。字符S表示阿福所在的位置，
字符E表示公主所在的位置，字符#表示不能踏入的禁区，字符$表示传送门，
字符.表示该位置安全，数字字符0至4表示了宝石的类型。
阿福每次可以从当前的位置走到他上下左右四个方向上的任意一个位置，
但不能走出地图边界。阿福每走一步需要花费1个单位时间，
从一个传送门到达另一个传送门不需要花费时间。当阿福走到宝石所在的位置时，就视为得到了该宝石，不需要花费额外时间。
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <bitset>
using namespace std;

struct State {
    int x, y;       // 位置
    int mask;       // 宝石状态，用5位二进制表示
    State(int _x, int _y, int _mask) : x(_x), y(_y), mask(_mask) {}
};

int T, R, C, K;
vector<string> grid;
vector<pair<int, int>> portals;  // 传送门位置
int startX, startY, endX, endY;

// 方向数组
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// 检查位置是否合法
bool isValid(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C && grid[x][y] != '#';
}

// 获取宝石类型，如果不是宝石返回-1
int getGemType(char c) {
    if (c >= '0' && c <= '4') return c - '0';
    return -1;
}

// 双向BFS
int bidirectionalBFS() {
    if (startX == -1 || endX == -1) return -1;
    
    // 状态空间：R x C x 32
    vector<vector<vector<int>>> dist1(R, vector<vector<int>>(C, vector<int>(32, -1)));
    vector<vector<vector<int>>> dist2(R, vector<vector<int>>(C, vector<int>(32, -1)));
    
    queue<State> q1, q2;
    
    // 起点状态
    int startMask = 0;
    if (int gem = getGemType(grid[startX][startY]); gem != -1) {
        startMask |= (1 << gem);
    }
    dist1[startX][startY][startMask] = 0;
    q1.push(State(startX, startY, startMask));
    
    // 终点状态，终点可以以任意宝石状态开始
    dist2[endX][endY][0] = 0;
    q2.push(State(endX, endY, 0));
    
    // 记录传送门位置
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == '$') {
                portals.push_back({i, j});
            }
        }
    }
    
    // 辅助函数：BFS扩展一步
    auto expand = [&](queue<State>& q, vector<vector<vector<int>>>& dist, bool isForward) {
        int size = q.size();
        while (size--) {
            State cur = q.front();
            q.pop();
            
            int x = cur.x, y = cur.y, mask = cur.mask;
            int curDist = dist[x][y][mask];
            
            // 检查是否相遇
            if ((isForward && dist2[x][y][mask] != -1) || 
                (!isForward && dist1[x][y][mask] != -1)) {
                // 检查宝石数量是否满足要求
                int totalMask = mask;
                if (isForward) totalMask |= mask;  // 实际上就是mask
                if (__builtin_popcount(totalMask) >= K) {
                    return curDist + (isForward ? dist2[x][y][mask] : dist1[x][y][mask]);
                }
            }
            
            // 如果是传送门，可以瞬间移动到其他传送门
            if (grid[x][y] == '$' && !portals.empty()) {
                for (auto& portal : portals) {
                    int nx = portal.first, ny = portal.second;
                    if (nx == x && ny == y) continue;
                    
                    if (dist[nx][ny][mask] == -1) {
                        dist[nx][ny][mask] = curDist;
                        q.push(State(nx, ny, mask));
                    }
                }
            }
            
            // 四个方向移动
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                
                if (!isValid(nx, ny)) continue;
                
                int newMask = mask;
                if (int gem = getGemType(grid[nx][ny]); gem != -1) {
                    newMask |= (1 << gem);
                }
                
                if (dist[nx][ny][newMask] == -1) {
                    dist[nx][ny][newMask] = curDist + 1;
                    q.push(State(nx, ny, newMask));
                }
            }
        }
        return -1;  // 没有相遇
    };
    
    // 双向BFS主循环
    while (!q1.empty() || !q2.empty()) {
        // 从起点扩展
        if (!q1.empty()) {
            int result = expand(q1, dist1, true);
            if (result != -1) return result;
        }
        
        // 从终点扩展
        if (!q2.empty()) {
            int result = expand(q2, dist2, false);
            if (result != -1) return result;
        }
    }
    
    return -1;  // 没有找到路径
}

int main() {
    cin >> T;
    
    while (T--) {
        cin >> R >> C >> K;
        
        grid.resize(R);
        portals.clear();
        startX = startY = endX = endY = -1;
        
        // 读取地图
        for (int i = 0; i < R; i++) {
            cin >> grid[i];
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (grid[i][j] == 'E') {
                    endX = i;
                    endY = j;
                }
            }
        }
        
        int result = bidirectionalBFS();
        
        if (result == -1) {
            cout << "oop" << endl;
        } else {
            cout << result << endl;
        }
    }
    
    return 0;
}