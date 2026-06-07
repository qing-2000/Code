#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    // 1. 找出数组中的最大值和最小值
    int maxVal = arr[0];
    int minVal = arr[0];
    for (int num : arr) {
        maxVal = max(maxVal, num);
        minVal = min(minVal, num);
    }

    // 2. 创建计数数组（偏移量 = minVal，节省空间）
    int range = maxVal - minVal + 1;
    vector<int> count(range, 0);

    // 3. 统计每个值出现的次数
    for (int num : arr) {
        count[num - minVal]++;
    }

    // 4. 将计数数组转换为前缀和（确定每个值在输出数组中的最终位置）
    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    // 5. 从后向前遍历原数组，将元素放到输出数组的正确位置（保持稳定性）
    vector<int> output(arr.size());
    for (int i = arr.size() - 1; i >= 0; --i) {
        int idx = arr[i] - minVal;
        output[count[idx] - 1] = arr[i];
        count[idx]--;
    }

    // 6. 将排序结果复制回原数组
    arr = output;
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countingSort(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    // 输出：1 2 2 3 3 4 8
    return 0;
}