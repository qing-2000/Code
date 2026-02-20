#include <iostream>
//超时，可通过判断是否为质数和的动态规划解
using namespace std;
bool func(int a) {
    for (int i = 2; i < a; i++) {
        if (a % i == 0)return false;
    }
    return true;
}//判断质数
int function(int a) {
    int count = 1;
    if (a < 2)return 0;
    for (int i = a - 1; i > 1; i--) {
        if (func(i) && a - i >= 0) {
            a -= i;
            if (count % 2 == 1 && a < 2)return 1;
            else if (count % 2 == 0 && a < 2)return 0;
            count++;
        }
    }
}

int main()
{
    // 请在此输入您的代码
    int n, a[100010] = { 0 }, lenth;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> lenth;
        a[i] = function(lenth);
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}