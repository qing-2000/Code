#include <iostream>
#include <string>
using namespace std;

string s; // 全局密文

// 递归解密，返回区间 [l, r) 对应的明文字符串
string dfs(int l, int r) {
    if (l >= r) return "";
    int len = r - l;
    // 原始字符串长度为 len 时，中间轴位置 (1-indexed) 为 (len+1)/2
    int mid = (len + 1) / 2;
    char c = s[l];                     // 密文第一个字符就是中间轴
    int left_len = mid - 1;            // 左半部分长度
    int right_len = len - mid;         // 右半部分长度
    string left = dfs(l + 1, l + 1 + left_len);
    string right = dfs(l + 1 + left_len, r);
    return left + c + right;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    int n = s.length();
    string ans = dfs(0, n);
    cout << ans << endl;
    return 0;
}