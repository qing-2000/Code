#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 请在此输入您的代码
    string s="snake";//抽象（指出题人）
    int c[26] = { 0 };
    //getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        c[s[i] - 'a']++;
    }
    for (int i = 0; i < 26;i++) {
        int temp = c[i];
        while (temp > 0) {
            printf("%c", i + 'a');
            temp--;
        }
    }
    return 0;
}