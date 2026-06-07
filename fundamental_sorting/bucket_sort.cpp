#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 桶排序主函数（适用于非负浮点数，可轻松改为整数）
void bucketSort(vector<float>& arr) {
    if (arr.empty()) return;

    // 1. 找出最大值和最小值
    float maxVal = arr[0], minVal = arr[0];
    for (float num : arr) {
        maxVal = max(maxVal, num);
        minVal = min(minVal, num);
    }

    // 2. 初始化桶
    int bucketCount = arr.size();  // 桶的数量一般取数组长度
    vector<vector<float>> buckets(bucketCount);

    // 3. 将元素分配到桶中
    for (float num : arr) {
        // 计算应该放入哪个桶（确保索引范围 [0, bucketCount-1]）
        int idx = (int)((num - minVal) / (maxVal - minVal) * (bucketCount - 1));
        buckets[idx].push_back(num);
    }

    // 4. 对每个桶内部排序（这里使用标准库的 sort，也可用插入排序优化）
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
    }

    // 5. 合并所有桶
    arr.clear();
    for (auto& bucket : buckets) {
        arr.insert(arr.end(), bucket.begin(), bucket.end());
    }
}

// 针对整数的简化版本（假设数据范围 [0, max)）
void bucketSortInt(vector<int>& arr, int maxVal) {
    if (arr.empty()) return;

    int bucketCount = arr.size();
    vector<vector<int>> buckets(bucketCount);

    // 分配到桶
    for (int num : arr) {
        int idx = (num * bucketCount) / (maxVal + 1); // 确保索引在 [0, bucketCount-1]
        buckets[idx].push_back(num);
    }

    // 桶内排序
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
    }

    // 合并
    arr.clear();
    for (auto& bucket : buckets) {
        arr.insert(arr.end(), bucket.begin(), bucket.end());
    }
}

// 测试代码
int main() {
    // 浮点数版本
    vector<float> arr = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    bucketSort(arr);
    for (float num : arr) cout << num << " ";
    cout << endl;
    // 输出：0.23 0.25 0.32 0.42 0.47 0.51 0.52

    // 整数版本
    vector<int> arrInt = {5, 3, 8, 1, 9, 2, 7, 4, 6};
    bucketSortInt(arrInt, 9);
    for (int num : arrInt) cout << num << " ";
    // 输出：1 2 3 4 5 6 7 8 9
    return 0;
}