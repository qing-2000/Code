// lanqiao4977.cpp: 定义应用程序的入口点。
//

#include "lanqiao4977.h"
#include <iostream>
#include<cstring>
#include<algorithm>
#include<cctype>
using namespace std;
#define N 100
int main()
{
    // 请在此输入您的代码
    int n = -1;
    
    do {
        cout << "请输入字符串数量（0-50）: ";
        cin >> n;
    } while (n < 0 || n > 50);
    cout << endl;
    string str[N];
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    for (int i = 0; i < n; i++) {
        for (char& c : str[i]) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = toupper(c);
            }
            else {
                c = tolower(c);
            }
        }
        cout << str[i] << endl;
    }
    return 0;
}