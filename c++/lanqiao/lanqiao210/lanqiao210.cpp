#include <iostream>
using namespace std;
int asd(int a, int b) {
    int c = 0, n = a, m = b;
    while (c = a % b) {
        a = b;
        b = c;
    }
    return n * m / b;
}
int main()
{
    // 请在此输入您的代码
    int a, b, c;
    do {
        cin >> a >> b >> c;
    } while (a + b + c >= 30);
    cout << asd(asd(a, b), c);
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int max = a, num;
    max = (max > b ? max : b) > c ? (max > b ? max : b) : c;

    for (int i = 1; i < 10000; i++) {
        num = max * i;
        if (num % a == 0 && num % b == 0 && num % c == 0) {
            break;
        }
    }
    cout << num << endl;
    return 0;
}