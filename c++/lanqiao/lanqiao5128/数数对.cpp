#include <iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int ans;
    int n, m;
    cin >> n >> m;
    cin.ignore();
    string s;
    for (int i = 0; i < m; i++) {
        ans = 1;
        getline(cin, s);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L')ans += (ans - 1);
            if (s[i] == 'R')ans *= 2;
        }
        cout << ans << endl;
    }
    return 0;
}
