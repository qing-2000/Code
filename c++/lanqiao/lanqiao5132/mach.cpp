//超时了
#include <iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
bool function(vector<char>&s1, string s2) {
    int n = s2.size();
    for (int i =0; i < n; i++)if (abs(s1[i] - s2[i]) != 32)return false;
    return true;
}
int main()
{
    // 请在此输入您的代码
    int a[26] = { 0 }, b[26] = { 0 };
    int n;
    cin >> n;
    cin.ignore();
    string s2;
    vector<char>s1(n);
    for (int i = 0; i < n; i++)cin >> s1[i];
    cin.ignore();
    getline(cin, s2);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!function(s1, s2)) {
            ans++;
            char temp = s1[0];
            s1.erase(s1.begin(), s1.begin()+1);
            s1.push_back(temp);
        }
    }
    if (function(s1, s2))cout << "Yes" << endl << ans; else cout << "No";
    return 0;
}