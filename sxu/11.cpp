#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBigNumbers(string num1, string num2) {
    // 去除前导0
    num1.erase(0, num1.find_first_not_of('0'));
    num2.erase(0, num2.find_first_not_of('0'));
    if (num1.empty()) num1 = "0";
    if (num2.empty()) num2 = "0";
    
    // 反转字符串
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    
    // 结果字符串
    string result = "";
    int carry = 0;
    int maxLen = max(num1.length(), num2.length());
    
    for (int i = 0; i < maxLen || carry; i++) {
        int digit1 = (i < num1.length()) ? num1[i] - '0' : 0;
        int digit2 = (i < num2.length()) ? num2[i] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    
    // 反转结果并去除前导0
    reverse(result.begin(), result.end());
    result.erase(0, result.find_first_not_of('0'));
    if (result.empty()) result = "0";
    
    return result;
}

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    
    cout << addBigNumbers(s1, s2) << endl;
    
    return 0;
}
/*
vector<int> bigIntegerAdd(vector<int>& num1, vector<int>& num2) {
    if (num1.size() < num2.size()) {
        return bigIntegerAdd(num2, num1);
    }
    
    vector<int> result;
    int carry = 0;
    
    for (int i = 0; i < num1.size(); i++) {
        int sum = num1[i] + carry;
        if (i < num2.size()) {
            sum += num2[i];
        }
        
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    
    if (carry > 0) {
        result.push_back(carry);
    }
    
    return result;
}
vector<int> createVectorFromString(string s) {
    vector<int> num;
    for (int i = s.length() - 1; i >= 0; i--) {
        num.push_back(s[i] - '0');
    }
    return num;
}
void printVector(vector<int>& num) {
    for (int i = num.size() - 1; i >= 0; i--) {
        if(num[i]==0)continue;
        cout << num[i];
    }
    cout << endl;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> num1 = createVectorFromString(s1);
    vector<int> num2 = createVectorFromString(s2);
    vector<int> sum = bigIntegerAdd(num1, num2);
    printVector(sum);
    
    return 0;
}
*/