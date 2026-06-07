#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 获取数字 num 的第 exp 位（个位 exp=1，十位 exp=10，百位 exp=100...）
int getDigit(int num, int exp) {
    return (num / exp) % 10;
}

// 对数组 arr 按第 exp 位进行计数排序
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n, 0);      // 存储临时排序结果
    vector<int> count(10, 0);      // 0~9 共10个桶

    // 统计每个数字出现的次数
    for (int i = 0; i < n; ++i) {
        int digit = getDigit(arr[i], exp);
        count[digit]++;
    }

    // 将 count 转换为前缀和，以便确定每个数字在输出数组中的位置
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // 从后向前遍历，保持稳定性
    for (int i = n - 1; i >= 0; --i) {
        int digit = getDigit(arr[i], exp);
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // 将排序结果复制回原数组
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

// 基数排序主函数
void radixSort(vector<int>& arr) {
    if (arr.empty()) return;

    // 找出最大值，确定最大位数
    int maxVal = *max_element(arr.begin(), arr.end());

    // 对每一位进行计数排序
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

// 测试代码
int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    // 输出：2 24 45 66 75 90 170 802
    return 0;
}