#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool function1(char c) {
    return (c == 'l' || c == 'q' || c == 'b');
}

void removefunction(string& s) {
    s.erase(remove_if(s.begin(), s.end(), function1), s.end());
}

bool judgefunction(string s) {
    if (s.empty()) return true;
    auto h = s.begin(), t = s.end() - 1;
    while (h <= t) {
        if (*h != *t) return false;
        h++;
        t--;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();  // 清除换行符

    vector<string> m(n);
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);  // 直接读取n行
        cin.ignore();
        removefunction(s);
        m[i] = judgefunction(s) ? "Yes" : "No";
    }

    for (auto ch : m) cout << ch << endl;
    return 0;
}