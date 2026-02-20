#include <iostream>
#include <vector>
#include <algorithm>  // 用于max函数
using namespace std;

int main() {
    // 读取输入数据
    int N, K;
    cin >> N >> K;

    // 创建存储巧克力尺寸的容器
    vector<pair<int, int>> chocolates(N);
    int max_edge = 0;  // 记录所有巧克力中的最大边长

    // 读取每个巧克力的尺寸
    for (int i = 0; i < N; ++i) {
        cin >> chocolates[i].first >> chocolates[i].second;
        // 动态更新最大可能边长（取长和宽中的较大者）
        max_edge = max({ max_edge, chocolates[i].first, chocolates[i].second });
    }

    // 二分查找初始化
    int left = 1;              // 最小可能的边长
    int right = max_edge;      // 最大可能的边长
    int ans = 0;               // 最终答案

    // 二分查找主循环
    while (left <= right) {
        int mid = (left + right) / 2;  // 取中间值作为候选边长
        int cnt = 0;                   // 当前边长能切出的总块数

        // 遍历所有巧克力计算总块数
        for (auto& choco : chocolates) {
            // 计算当前巧克力能切出多少块 mid×mid 的巧克力
            cnt += (choco.first / mid) * (choco.second / mid);

            // 优化：当已经满足需求时提前退出循环
            if (cnt >= K) break;
        }

        // 判断条件是否满足
        if (cnt >= K) {
            ans = mid;        // 更新可行解
            left = mid + 1;   // 尝试寻找更大的边长
        }
        else {
            right = mid - 1;  // 需要减小边长
        }
    }

    // 输出最终答案
    cout << ans;
    return 0;
}