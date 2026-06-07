#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// 大数加法（正整数）
string add(const string& a, const string& b) {
    string res;
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

// 大数乘以2（即自身相加）
string mul2(const string& s) {
    return add(s, s);
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    if (n == 1) {
        cout << a << endl;
        return 0;
    }
    if (n == 2) {
        cout << b << endl;
        return 0;
    }
    vector<string> dp(n + 1);
    dp[1] = to_string(a);
    dp[2] = to_string(b);
    for (int i = 3; i <= n; ++i) {
        dp[i] = add(mul2(dp[i-1]), dp[i-2]);
    }
    cout << dp[n] << endl;
    return 0;
}
// #include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace std;
// using namespace boost::multiprecision;

// int main(){
//     int a,b,n;
//     cin>>a>>b>>n;

//     vector<cpp_int> ans(n+1);       cpp_int 无限大取决于内存空间
//     ans[1]=a;
//     ans[2]=b;

//     for(int i=3;i<=n;i++){
//         ans[i]=2*ans[i-1]+ans[i-2];
//     }

//     cout<<ans[n];
//     return 0;
// }