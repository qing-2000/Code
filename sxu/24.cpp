#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int k;
    cin >> k;
    vector<int> ans(k, 0);
    while (k)
    {
        string gender;
        double a, b, c, d, e;
        cin >> gender >> a >> b >> c >> d >> e;
        if (gender == "male")
        {
            if (a < 4 || a > 10)
            {
                ans[k - 1] += 1;
            }
            if (b < 3.5 || b > 5.5)
            {
                ans[k - 1] += 1;
            }
            if (c < 120 || c > 160)
            {
                ans[k - 1] += 1;
            }
            if (d < 42 || d > 48)
            {
                ans[k - 1] += 1;
            }
            if (e < 100 || e > 300)
            {
                ans[k - 1] += 1;
            }
        }
        if (gender == "female")
        {
            if (a < 4 || a > 10)
            {
                ans[k - 1] += 1;
            }
            if (b < 3.5 || b > 5.5)
            {
                ans[k - 1] += 1;
            }
            if (c < 110 || c > 150)
            {
                ans[k - 1] += 1;
            }
            if (d < 36 || d > 40)
            {
                ans[k - 1] += 1;
            }
            if (e < 100 || e > 300)
            {
                ans[k - 1] += 1;
            }
        }

        k--;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == 0)
            cout << "normal" << endl;
        else
            cout << ans[i] << endl;
    }
    return 0;
}