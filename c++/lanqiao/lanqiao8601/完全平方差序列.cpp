#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    unordered_set<long long> unique_nums;
    vector<long long> nums;

    // 生成所有可能的平方差
    for (long long a = 1; ; ++a) {
        // 提前终止条件：当生成的数足够覆盖前n个时
        if (!nums.empty() && nums.size() >= n && a > 2 * nums.back()) break;

        for (long long b = 0; b < a; ++b) {
            long long temp = a * a - b * b;
            if (temp <= 0) continue;

            if (unique_nums.insert(temp).second) {
                nums.push_back(temp);
            }
        }
    }

    // 排序并去重
    sort(nums.begin(), nums.end());

    // 输出第n小的数
    if (n <= nums.size()) {
        cout << nums[n - 1];
    }
    else {
        cout << "Not enough valid numbers found";
    }

    return 0;
}