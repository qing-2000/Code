#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 辅助函数：比较两个大数（字符串形式）的大小
// 返回 1 表示 a > b, 0 表示 a == b, -1 表示 a < b
int compare(const string& a, const string& b) {
    if (a.length() != b.length())
        return a.length() > b.length() ? 1 : -1;
    for (size_t i = 0; i < a.length(); ++i) {
        if (a[i] != b[i])
            return a[i] > b[i] ? 1 : -1;
    }
    return 0;
}

// 辅助函数：大数减法，要求 a >= b
string subtract(const string& a, const string& b) {
    string res;
    int len1 = a.length(), len2 = b.length();
    int borrow = 0;
    // 从低位开始减，所以反转字符串
    string ra = a, rb = b;
    reverse(ra.begin(), ra.end());
    reverse(rb.begin(), rb.end());
    for (int i = 0; i < len1; ++i) {
        int digit_a = ra[i] - '0' - borrow;
        int digit_b = (i < len2) ? rb[i] - '0' : 0;
        borrow = 0;
        if (digit_a < digit_b) {
            digit_a += 10;
            borrow = 1;
        }
        res.push_back((digit_a - digit_b) + '0');
    }
    // 去除结果末尾的0（即高位多余的0），注意反转后低位在前
    while (res.length() > 1 && res.back() == '0')
        res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

// 辅助函数：大数乘以一位数
string multiply(const string& a, int digit) {
    if (digit == 0) return "0";
    string res;
    int carry = 0;
    // 从低位开始乘
    string ra = a;
    reverse(ra.begin(), ra.end());
    for (size_t i = 0; i < ra.length(); ++i) {
        int prod = (ra[i] - '0') * digit + carry;
        res.push_back(prod % 10 + '0');
        carry = prod / 10;
    }
    if (carry) res.push_back(carry + '0');
    reverse(res.begin(), res.end());
    return res;
}

// 主函数：大数除法，返回商和余数（通过引用返回余数）
string divide(const string& dividend, const string& divisor, string& remainder) {
    // 处理除数为0的情况（题目保证不会出现，但为了安全）
    if (divisor == "0") {
        remainder = "0";
        return "ERROR";
    }
    // 去除前导零（但保留至少一位）
    string a = dividend;
    string b = divisor;
    a.erase(0, a.find_first_not_of('0'));
    b.erase(0, b.find_first_not_of('0'));
    if (a.empty()) a = "0";
    if (b.empty()) b = "0";

    // 如果被除数小于除数，商为0，余数为被除数
    if (compare(a, b) < 0) {
        remainder = a;
        return "0";
    }

    string quotient = "";
    string current = ""; // 当前处理的数（相当于手算中的“余数”加上新落下的位）

    for (size_t i = 0; i < a.length(); ++i) {
        // 将下一位数字加入当前数
        current += a[i];
        // 去除 current 的前导零（但保留至少一位）
        current.erase(0, current.find_first_not_of('0'));
        if (current.empty()) current = "0";

        // 试商：从9到0尝试
        int q = 0;
        for (int d = 9; d >= 0; --d) {
            string product = multiply(b, d);
            // 如果 product <= current
            if (compare(product, current) <= 0) {
                q = d;
                // 计算新的余数 current = current - product
                current = subtract(current, product);
                break;
            }
        }
        // 将这一位商加入结果
        quotient.push_back(q + '0');
    }

    // 去除商的前导零
    quotient.erase(0, quotient.find_first_not_of('0'));
    if (quotient.empty()) quotient = "0";

    // 最后的 current 就是余数
    remainder = current;
    // 余数可能为"0"（即空串），需要处理
    if (remainder.empty()) remainder = "0";

    return quotient;
}

int main() {
    string dividend, divisor;
    // 输入被除数和除数，每行一个
    getline(cin, dividend);
    getline(cin, divisor);

    string remainder;
    string quotient = divide(dividend, divisor, remainder);

    // 输出商和余数，根据题目要求可能只需要商，这里同时输出供测试
    cout << "商: " << quotient << endl;
    cout << "余数: " << remainder << endl;

    return 0;
}