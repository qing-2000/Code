#include <iostream>
using namespace std;
int main()
{
    // 请在此输入您的代码
    char a[26] = { 0 };
    int i = 0;
    long long n;
    cin >> n;
    while (n > 0) {
        a[i++] = n % 26 - 1 + 'A';
        n /= 26;
    }
    for (int j = i-1; j > -1; j--)cout << a[j];
    return 0;
}