#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    bool flag1 = true, flag2 = true, res = false;
    vector<int> ans;
    int temp = n;
    while (temp)
    {
        ans.emplace_back(temp % 10);
        temp /= 10;
    }
    int len = ans.size();
    int pre = 0, end = len - 1;

    while (pre < len)
    {
        if (ans[pre] != ans[end])
        {
            flag1 = false;
            break;
        }
        pre++;
        end--;
    }
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n / i == 0)
        {
            flag2 = false;
            break;
        }
    }
    if (flag1 && flag2)
        res = true;
    if (res)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}