#include <iostream>
#include <vector>
using namespace std;

// 调整以 root 为根的子树，使其满足大顶堆性质
// n 为堆的大小，root 为当前根节点下标（0-based）
void heapify(vector<int>& arr, int n, int root) {
    int largest = root;       // 初始化最大值为根节点
    int left = 2 * root + 1;  // 左子节点下标
    int right = 2 * root + 2; // 右子节点下标

    // 如果左子节点存在且大于当前最大值
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点存在且大于当前最大值
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是根节点，交换并继续调整
    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest); // 递归调整受影响的子树
    }
}

// 堆排序主函数
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 第一步：建堆（从最后一个非叶子节点开始向上调整）
    // 最后一个非叶子节点下标为 n/2 - 1
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    // 第二步：排序（将堆顶元素与末尾元素交换，然后缩小堆范围并调整）
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);   // 将当前最大值移到末尾
        heapify(arr, i, 0);     // 调整剩余元素，重新形成大顶堆
    }
}

// 测试代码
int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    heapSort(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    // 输出：5 6 7 11 12 13
    return 0;
}