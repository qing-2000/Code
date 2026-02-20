#include <iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    // 请在此输入您的代码
    string str;
    cin >> str;
    int count[26] = { 0 };
    for (char c : str) {
        count[(c - 'a')]++;
    }//a-z中26个字母出现的次数数组
    int sum = 0;//记录出现最多次数的字母的次数
    char result_cha = 'a';//记录出现最多次数的字母
    for (int i = 0; i < 26; i++) {
        if (count[i] > sum)
        {
            sum = count[i];
            result_cha = 'a' + i;//通过AS||码实现a-z的转变
        }
        else if (count[i] == sum && 'a' + i < result_cha) {
            result_cha = 'a' + i;
        }

    }
    cout << result_cha << "\n" << sum;
    return 0;
}