#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n, q, position, val, temp, mod = 10000007,sum=1;
    cin >> n >> q;
    sum=sum << n;
    
    vector<int>a(sum);
    vector<int>ans(q);
    for (int i = 0; i < sum; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++) {
        temp = 1;
        cin >> position >> val;
        a[position - 1] = val;
        for (auto& num : a) {
            temp *= num;
        }//可优化，在输入数组时就求取累加和，
        //通过费马小定理（未能理解）/要替换的位置的值*替换后的值，缩减时间复杂度
        ans[i] = temp % mod;
    }
    for (auto& n : ans)cout << n << endl;
    return 0;
}