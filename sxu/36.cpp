#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    int a, b;
    string n;
    cin >> a >> n >> b;

    // 将a进制字符串n转换为十进制数
    long long decimal = 0;
    for (char c : n) {
        int digit;
        if (isdigit(c)) {
            digit = c - '0';
        } else {
            digit = toupper(c) - 'A' + 10;
        }
        decimal = decimal * a + digit;
    }

    // 将十进制数转换为b进制
    string result;
    if (decimal == 0) {
        result = "0";
    } else {
        while (decimal > 0) {
            int remainder = decimal % b;
            char ch;
            if (remainder < 10) {
                ch = remainder + '0';
            } else {
                ch = remainder - 10 + 'A';
            }
            result.push_back(ch);
            decimal /= b;
        }
        reverse(result.begin(), result.end());
    }

    cout << result << endl;
    return 0;
}