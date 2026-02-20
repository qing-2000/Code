#include <iostream>
using namespace std;
typedef unsigned long long ull;
const ull mod = 998244353;

ull f(ull n) {
    if (n <= 10) return n * (n - 1) % mod;
    ull dp[n + 1];
    for (ull i = 0; i <= 10; i++) dp[i] = i * (i - 1) % mod;
    for (ull i = 11; i <= n; i++)
        dp[i] = dp[i - 6] * i % mod * 2 % mod;
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}