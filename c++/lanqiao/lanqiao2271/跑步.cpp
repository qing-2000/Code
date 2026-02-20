#include <iostream>
using namespace std;
int main()
{
    int count = 1, ans = 0, temp;;//从周六开始的计数
    int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    for (int i = 1; i < 13; i++) {
        temp = 1;//天数
        while (temp <= arr[i]) {
            if (temp == 1 || temp == 11 || temp == 21 || temp == 31)ans++;
            else if (count == 1 || count == 2)ans++;
            count += 1;
            if (count == 7) {
                count = 0;
            }
            temp++;
        }
    }
    cout << ans;
    return 0;
}