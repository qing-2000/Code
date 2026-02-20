#include <iostream>
#include<cmath>
using namespace std;
int asd(int n) {
    int temp = 1;
    for (int i = 0; i < n; i++) {
        temp *= 7;
    }
    return temp;
}
int main()
{
    //声明数组存储7的n次方的次数
    int sum2 = 1000000, ans = 0;
    int arr[8] = { 1,1,1,1,1,1,1,1 };
    sum2 = sum2 - 1 - 7 - 49 - 343 - 2401 - 16807 - 117649 - 823543;
    for (int i = 7; i >= 0;i--) {
        if (sum2 > asd(i)) {
            sum2 -= asd(i);
            if (sum2 < 0) {
                sum2 += asd(i);
            }
            else {
                while (sum2 >= 0) {
                    arr[i]++;
                    sum2 -= asd(i);
                    if (sum2 < 0) {
                        sum2 += asd(i);
                        break;
                    };
                }
            }
        }
    }
    for (auto& ch : arr) {
        ans += ch;
    }
    cout << ans;  
}