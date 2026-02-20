#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 请在此输入您的代码
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a[10000] = { 0 },add=0,temp=0;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            int l, r, lsum = 0, rsum = 0;
            l = i - 1; r = i + 1;
            while (l > -1) {
                lsum++;
                if (s[l] == '1') {
                    break;
                }
                if ((l == 0) && (s[0]=='0')) {
                    lsum = 0;
                    break;
                 }
                l--;
            }
            while (r<n) {
                rsum++;
                if (s[r] == '1') {
                    break;
                }
                if((r == n-1) && (s[n-1] == '0')) {
                    rsum = 0;
                    break;
                }
                r++;
            }
            temp = min(lsum,rsum);
            if (temp > 0)a[add] = temp;
            else if (lsum > 0)a[add] = lsum;
            else if (rsum > 0)a[add] = rsum;
            else a[add] = -1;
            add++;
        }
    }
    for (int i = 0; i < add; i++) {
       cout << a[i] << " ";
    }
    return 0;
}