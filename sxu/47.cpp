#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int k;
    cin >> k;
    if (k <= 0)
    {
        cout << 0;
        return 0;
    }
    if (k < 2)
    {
        cout << 1;
        return 0;
    }
    if (k == 2)
    {
        cout << 1;
        return 0;
    }
    if (k >= 3)
    {
        vector<int> ans(k, 0);
        ans[0] = 1, ans[1] = 1;
        for (int i = 2; i < k; i++)
        {
            ans[i] = ans[i - 1] + ans[i - 2];
        }
        cout << ans[k - 1];
    }

    return 0;
}