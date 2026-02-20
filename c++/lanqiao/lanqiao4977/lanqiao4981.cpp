#include <iostream>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n, sum = 0;
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++) {
        sum += cin >> sum;
    }
    cout << sum;
    return 0;
}