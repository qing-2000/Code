#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<pair<int, int>> movies(n);
        for (int i = 0; i < n; ++i) {
            cin >> movies[i].first >> movies[i].second;
        }
        // 按结束时间排序
        sort(movies.begin(), movies.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        int count = 0;
        int last_end = -1;
        for (const auto& m : movies) {
            if (m.first >= last_end) { // 可以看（端点重合允许）
                count++;
                last_end = m.second;
            }
        }
        cout << count << endl;
    }
    return 0;
}