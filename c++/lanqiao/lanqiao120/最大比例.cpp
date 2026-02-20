#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}
int main()
{
    // 请在此输入您的代码
    int n, a[100] = { 0 }, temp;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x, y ;
    for (int i = 0; i < 2; i++) {
        if (i == 0)x = a[i];
        if (i == 1)y = a[1];
    }
    temp = gcd(x, y);
    cout << x<<" "<<y << endl;
    if (temp > 0) {
        while (x >= temp && y >= temp) {
            x /= temp;
            y /= temp;
        }
        cout << x << "/" << y;
    }else cout << x << "/" << y;
    return 0;
}