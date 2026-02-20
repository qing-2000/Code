#include <iostream>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int a, b, c;
    string str[100];
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> b >> c;
        if (c >= (b / 2.00)) {
            str[i] = "YES";
        }
        else {
            str[i] = "NO";
        }
    }
    for (int i = 0; i < a; i++) {
        cout << str[i] << endl;
    }
    return 0;
}