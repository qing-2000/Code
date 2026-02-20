#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n, x, mx = 0, mn = 0;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cin >> x;
        mx = mx > x ? mx : x;
        mn = mn < x ? mn : x;
    }
    cout << (mx - fabs(mn)) / 2;
    return 0;
}