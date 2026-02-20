#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n,x, temp;
    double a, b;
    cin >> n >> x;
    int brr[100000] = { 0 };
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        temp = 0;
        while (a && b) {
            if (a * b == x) { brr[i] = 1; break; }
            if (temp % 2 == 0) {
                a /= 2;
                temp++;
            }
            else {
                b /= 2; temp++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if(brr[i]==1)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}