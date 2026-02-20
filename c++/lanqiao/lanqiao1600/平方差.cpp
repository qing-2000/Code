#include <iostream>
#include<vector>
using namespace std;
#define Maxsize 2000
bool quza(int i, int a[]) {
    for (int n = 0; n < Maxsize; n++) {
        if (i == a[n])return false;
    }
    return true;
}
int main()
{
    // 请在此输入您的代码
    int count = 0, i = 1, temp, j, k, a[Maxsize] = { 0 },m=0;
    while (i < 2022) {
        for (j = 1; j < 2022; j++) {
            for (k = 0; k < j; k++) {
                temp = j * j - k * k;
                if (i == temp&&quza(i,a)) {
                    cout << i << " ";
                    a[m++] = i;
                    count++;
                    break;
                }
            }
        }
        i++;
    }
    cout << count;
    return 0;
}