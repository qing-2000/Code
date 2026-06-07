#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long m, n;
    while (cin >> m >> n) {
        if (m == 0 && n == 0) break;
        long long left = m, right = m;
        long long total = 0;
        while (left <= n) {
            total += min(right, n) - left + 1;//当前层数节点数
            left = left * 2;
            right = right * 2 + 1;
        }
        cout << total << endl;
    }
    return 0;
}