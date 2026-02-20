#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int K;
    cin >> K;
    while (K--) {
        int N;
        cin >> N;
        vector<int> start(N), target(N);
        for (int i = 0; i < N; ++i) cin >> start[i];
        for (int i = 0; i < N; ++i) cin >> target[i];
        // 构建增广矩阵 a[N][N+1]
        vector<vector<int>> a(N, vector<int>(N + 1, 0));
        // 每个操作影响自身
        for (int i = 0; i < N; ++i) a[i][i] = 1;
        int I, J;
        while (cin >> I >> J, I || J) {
            // 操作I影响J，所以第J-1行第I-1列置1
            a[J - 1][I - 1] = 1;
        }
        // 右边常数：需要改变的状态
        for (int i = 0; i < N; ++i) {
            a[i][N] = start[i] ^ target[i];
        }
        // 高斯消元（异或版）
        int row = 0;
        for (int col = 0; col < N && row < N; ++col) {
            // 找主元
            int pivot = -1;
            for (int i = row; i < N; ++i) {
                if (a[i][col]) {
                    pivot = i;
                    break;
                }
            }
            if (pivot == -1) continue; // 自由元
            swap(a[row], a[pivot]);
            // 消去下面行的该列
            for (int i = row + 1; i < N; ++i) {
                if (a[i][col]) {
                    for (int j = col; j <= N; ++j) {
                        a[i][j] ^= a[row][j];
                    }
                }
            }
            ++row;
        }
        // 检查无解：剩余行左边全0但右边为1
        bool ok = true;
        for (int i = row; i < N; ++i) {
            if (a[i][N]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "Oh,it's impossible~!!" << endl;
        } else {
            long long ans = 1LL << (N - row);
            cout << ans << endl;
        }
    }
    return 0;
}