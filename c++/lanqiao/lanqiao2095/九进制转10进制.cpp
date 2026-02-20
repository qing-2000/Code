#include <iostream>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int a[4] = { 2,0,2,2 }, b[4] = { 0 }, num = 3;
    for (int i = 0; i < 3; i++) {
        while (a[i] > 0) {
            a[i + 1] += 9;
            a[i]--;
        }
    }
    int temp = a[3];
    while (temp) {
        b[num--] += temp % 10;
        temp /= 10;
    }
    for (int i = 0; i < 4;i++) {
        cout << b[i];
    }
    return 0;
}