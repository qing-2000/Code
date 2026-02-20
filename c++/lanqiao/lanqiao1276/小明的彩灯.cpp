#include <bits/stdc++.h>
using namespace std;
int main(){
    // 请在此输入您的代码
    long long N, Q, a[100000]={0}, b[100000] = {0}, l, r, x;
    cin >> N >> Q;
    for (long long i = 0; i < N; i++)cin >> a[i];
    long long k = 0;
    while (Q) {
        cin >> l >> r >> x;
        b[l - 1] += x;
        if (r < N)b[r]-=x;
        Q--;
    }
    for (int i = 0; i < N; i++) {
        k += b[i];
        a[i] += k;
        if (a[i] > 0)cout << a[i] << " ";
        else cout << 0 << " ";
    }
    return 0;
}