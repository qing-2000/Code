#include <iostream>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int count = 6, temp, sum = 0, i,ans=0;
    for (i = 22; i < 1000 && count < 24; i++) {

        int sum = i,temp=0;
        while (sum) {
            if (sum % 2 == 1)temp++;
            sum /= 2;
            
        }
        if (temp == 3) {
            count++;
            //break;
        }
        if (count == 23) {
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}