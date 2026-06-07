#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt = 0;
        while (n) {
            n /= 5;
            cnt += n;
        }
        cout << cnt << endl;
    }
    return 0;
}