#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    
    // 去除前导0
    s1.erase(0, s1.find_first_not_of('0'));
    s2.erase(0, s2.find_first_not_of('0'));
    
    // 处理全0情况
    if (s1.empty()) s1 = "0";
    if (s2.empty()) s2 = "0";
    
    int l1 = s1.length(), l2 = s2.length();
    int maxLen = l1 + l2;  // 乘积最大位数
    vector<int> a(maxLen, 0);
    
    // 模拟竖式乘法
    int count = 0;
    for(int i = l1 - 1; i >= 0; --i){
        int temp = maxLen - 1;
        for(int j = l2 - 1; j >= 0; --j){
            a[temp - count] += (s1[i] - '0') * (s2[j] - '0');
            --temp;
        }
        ++count;
    }
    
    // 处理进位（从低位到高位）
    for(int i = maxLen - 1; i > 0; --i){
        if(a[i] > 9){
            a[i - 1] += a[i] / 10;
            a[i] %= 10;
        }
    }
    
    // 输出结果，跳过前导0
    bool flag = false;
    for(int i = 0; i < maxLen; ++i){
        if(a[i] != 0) flag = true;
        if(flag) cout << a[i];
    }
    
    // 如果结果全为0，输出一个0
    if(!flag) cout << "0";
    cout << endl;
    
    return 0;
}
/*
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string multiply(string num1, string num2) {
    // 去除前导0
    num1.erase(0, num1.find_first_not_of('0'));
    num2.erase(0, num2.find_first_not_of('0'));
    
    // 处理空字符串（全为0的情况）
    if (num1.empty() || num2.empty()) return "0";
    
    int n1 = num1.size(), n2 = num2.size();
    vector<int> result(n1 + n2, 0);
    
    // 反转字符串，从低位开始计算
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    
    // 逐位相乘
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            result[i + j] += (num1[i] - '0') * (num2[j] - '0');
        }
    }
    
    // 处理进位
    for (int i = 0; i < n1 + n2; i++) {
        if (result[i] >= 10) {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
    }
    
    // 转换为字符串，反转回来
    string res = "";
    bool leadingZero = true;
    for (int i = n1 + n2 - 1; i >= 0; i--) {
        if (leadingZero && result[i] == 0) continue;
        leadingZero = false;
        res.push_back(result[i] + '0');
    }
    
    return res.empty() ? "0" : res;
}

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    
    cout << multiply(s1, s2) << endl;
    
    return 0;
}
*/