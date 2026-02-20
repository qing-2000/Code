#include <bits/stdc++.h>
//区间内满足等于两个数的平方差的数只有奇数和4的倍数
#define int unsigned long long
using namespace std;
int l = 0, r = 0, cnt = 0;
int sum(int x) {
    return x / 4 + (x + 1) / 2;
}
signed main() {
    cin >> l >> r;
    cout << sum(r) - sum(l - 1);
    return 0;
}