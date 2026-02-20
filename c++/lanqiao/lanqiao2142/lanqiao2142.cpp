#include <iostream>
#include<string>
#include<stdio.h>
using namespace std;
int main()
{
    // 请在此输入您的代码
    string str;
    cin >> str;
    int arr[26] = { 0 }, i = 0, max_result = 0;
   
    for (auto& ch : str) {
       arr[ch-'A']++;
    }
    for (auto& ch : arr) {
        if (ch> max_result) {
            max_result = ch;
        }
    }
    for (int i = 0; i < 26;i++) {
        if (arr[i] == max_result && arr[i] != 0)
            printf("%c", i + 'A');
    }
    return 0;
}