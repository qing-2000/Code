#include <iostream>
#include<vector>
#include<numeric>
#include<cmath>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n, k, ans = 0, index = 0;
    double t, ave, temp = 0, fan=0,m;

    cin >> n >> k >> t;
    vector<double>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (auto& num : a) {
        temp += num;
        index++;
        if (index == k)break;
    }
    ave = temp / k;
    for (auto& nn : a) {
        fan += pow(nn - ave, 2)/k;

        ans++;
        if (fan < t)break;
        else {
            ans = -1;
            break;
        }
        index--;
        if (index == 0)break;
    }
    cout << ans << endl;
    return 0;
}