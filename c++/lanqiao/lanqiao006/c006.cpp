#include <iostream>
#include<algorithm>
using namespace std;
const int N = 2e3 + 10;
string s;
int a[N];
int main()
{
    int n;
    cin >> n >> s;

    reverse(s.begin(), s.end());

    int pos = s.find(".");

    s.erase(pos, 1);

    int len = s.size();

    for (int i = 0; i < len; i++) a[i + 1] = s[i] - '0';

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= len; j++) a[j] *= 2;

        for (int j = 1; j <= len; j++) {
            if (a[j] >= 10) {
                a[j + 1]++;
                a[j] %= 10;
                if (j == len) len++;
            }
        }
    }
    if (a[pos] >= 5) a[pos + 1]++;

    for (int i = len; i >= pos+1; i--) cout << a[i];
    return 0;
}