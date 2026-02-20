#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 请在此输入您的代码
    string s;
    int temp = 0, max = 0;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') {
            temp++;
        }
        if (max < temp)max = temp;
        if (s[i] != 'a') {
            temp = 0;
        }
    }
    max += 1;
    while (max) {
        cout << 'a';
        max--;
    }
    return 0;
}