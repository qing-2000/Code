#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // 忽略第一行后的换行符
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        // 空字符串不合法
        if (s.empty()) {
            cout << 0 << endl;
            continue;
        }
        // 首字符必须是字母或下划线
        if (!(isalpha(s[0]) || s[0] == '_')) {
            cout << 0 << endl;
            continue;
        }
        bool valid = true;
        for (size_t j = 1; j < s.size(); ++j) {
            if (!(isalnum(s[j]) || s[j] == '_')) {
                valid = false;
                break;
            }
        }
        cout << (valid ? 1 : 0) << endl;
    }
    return 0;
}