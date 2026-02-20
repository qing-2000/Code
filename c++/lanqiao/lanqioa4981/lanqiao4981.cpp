#include <iostream>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n, sum = 0,temp;
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        sum += temp;
    }
    cout << sum;
    return 0;
}