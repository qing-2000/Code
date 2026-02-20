#include <iostream>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
   
    int wide=0, n=0, m=0;
    
    cin >> wide >> n >> m;
    vector<int> arr(wide );
    vector<int> brr(wide );
    int  ans, temp1, temp2, jiange;
    temp1 = n / wide;
    if (n % wide != 0)
        temp1++;//n真正行数

    temp2 = m / wide;
    if (m % wide != 0)
        temp2++;//m真正行数

    if (temp1 % 2 == 1) {//奇数行
        arr[wide - 1] = wide * temp1;
            for (int i = wide - 2; i >= 0; i--) {
                arr[i] = arr[i + 1] - 1;
            }
    }
    if (temp1 % 2 == 0) {//偶数行
        arr[0] = wide * temp1;
            for (int i = 1; i <= wide - 1; i++) {
                arr[i] = arr[i - 1] - 1;
            }
    }

    if (temp2 % 2 == 1) {//奇数行
        brr[wide - 1] = wide * temp2;
            for (int i = wide - 2; i >= 0; i--) {
                brr[i] = brr[i + 1] - 1;
            }
    }
    if (temp2 % 2 == 0) {//偶数行
        brr[0] = wide * temp2;
            for (int i = 1; i <= wide - 1; i++) {
                brr[i] = brr[i - 1] - 1;
            }
    }
    
    int index1 = 0, index2=0;
    for (auto& num : arr) {
        if (num == n)
        {
            break;
        }
        index1++;
    }
    for (auto& num : brr) {
        if (num == m) {
            break;
        }
        index2++;
        
    }
    
    std::cout << index1 << "\t" << index2 << endl;
    jiange = abs(index1 - index2);//差值为横向间隔
    
    ans = temp2 - temp1 + jiange;//temp2-temp1表示纵向间隔

    std::cout << ans;
    return 0;
}