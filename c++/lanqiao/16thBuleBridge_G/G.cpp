#include <bits/stdc++.h> 
#include <bitset> 
#include <vector> 
using namespace std;

const int N = 1010;
vector<int> g[N];    // 邻接表存储树结构 
int w[N];            // 节点权值（加工能力） 
bitset<N> dp[N];     // dp[u]表示以u为根的子树合法状态集合 

void dfs(int u, int fa) {
    // 叶子节点初始化 
    if (g[u].size() == 1 && u != 1) {
        dp[u].set(0);          // 删除节点的状态0 
        if (w[u] < N) dp[u].set(w[u]); // 保留节点的状态w[u] 
        return;
    }

    dp[u].set(0); // 初始化为空状态 
    for (int v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);

        // 分组背包转移：合并子节点状态 
        bitset<N> tmp;
        for (int s = 0; s <= w[u]; ++s) {
            if (dp[u].test(s)) {
                tmp |= dp[v] << s; // 合并子节点贡献 
            }
        }
        tmp &= bitset<N>().set().flip(w[u] + 1); // 过滤超过权值的状态 
        dp[u] = tmp;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;

    // 读取节点权值 
    for (int i = 1; i <= T; ++i) cin >> w[i];

    // 建树 
    for (int i = 0; i < T - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, -1); // 从根节点开始DP 

    // 查找最大合法值 
    int ans = 0;
    for (int j = min(w[1], N - 1); j >= 0; --j) {
        if (dp[1].test(j)) {
            ans = j;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}