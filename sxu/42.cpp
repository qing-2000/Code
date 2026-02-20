#include <iostream>
#include <vector>
using namespace std;

const int MOD = 2010;

int main() {
    int N;
    cin >> N;

    // 筛法求素数
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }

    // 完全背包求方案数
    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    for (int p = 2; p <= N; ++p) {
        if (is_prime[p]) {
            for (int i = p; i <= N; ++i) {
                dp[i] = (dp[i] + dp[i - p]) % MOD;
            }
        }
    }

    cout << dp[N] << endl;
    return 0;
}