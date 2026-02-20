#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 请在此输入您的代码
    long long n, k, a[100000] = { 0 }, num, ans = 0;
    cin >> n >> k;
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (long long i = 0; i < n; i++) {
        num = 0;
        for (long long j = i; j < n; j++) {
            num += a[j];
            if (num % k == 0) {
                ans++;
            }
            //else break;
        }
    }
    cout << ans;
    return 0;
}