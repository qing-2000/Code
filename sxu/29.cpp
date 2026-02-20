#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 比较两个数字字符串，返回1表示a>b，0相等，-1 a<b
int compare(const string& a, const string& b) {
    if (a.length() != b.length())
        return a.length() > b.length() ? 1 : -1;
    for (size_t i = 0; i < a.length(); ++i) {
        if (a[i] != b[i])
            return a[i] > b[i] ? 1 : -1;
    }
    return 0;
}

// 大数乘法（字符串形式）
string multiply(const string& a, const string& b) {
    if (a == "0" || b == "0") return "0";
    int len1 = a.length(), len2 = b.length();
    vector<int> res(len1 + len2, 0);
    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + res[i + j + 1];
            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }
    string result;
    for (int num : res) {
        if (!(result.empty() && num == 0))
            result.push_back(num + '0');
    }
    return result.empty() ? "0" : result;
}

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    
    string cur = "1";
    int x = 0;
    // 逐次乘a，直到 cur > b
    while (compare(cur, b) <= 0) {
        ++x;
        cur = multiply(cur, a);
    }
    cout << x - 1 << endl;
    return 0;
}