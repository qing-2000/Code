#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int m;
    cin >> m;
    while (m--) {
        int n, k;
        cin >> n >> k;
        vector<int> perm(n);
        for (int i = 0; i < n; ++i) {
            cin >> perm[i];
        }
        // 连续调用 k 次 next_permutation，自动处理循环
        for (int i = 0; i < k; ++i) {
            next_permutation(perm.begin(), perm.end());
        }
        for (int i = 0; i < n; ++i) {
            if (i > 0) cout << ' ';
            cout << perm[i];
        }
        cout << endl;
    }
    return 0;
}