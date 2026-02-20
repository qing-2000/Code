#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n;//输入n个数
    cin >> n;
    vector<pair<int, int>>arr(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int score = 0;
        if (x == 0) { // 处理数字0的特殊情况             
            score = 1;
        }
        else {
            int temp = x;
            while (temp > 0) {
                int digit = temp % 10;
                if (digit == 8)
                    score += 2;
                else if (digit == 0 || digit == 4 || digit == 6 || digit == 9)
                    score += 1;
                temp /= 10;
            }
        }
        arr[i] = { x, score };
    }
    sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
        if (a.second == b.second)
            return a.first<b.first; // 值降序         
        return a.second>b.second;   // 得分降序     
        });
    for (const auto& item : arr)cout << item.first << "\t";
    return 0;
}