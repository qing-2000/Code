#include <iostream>
using namespace std;

int* find_max_dynamic(int arr[], int len) {
    // 在堆上分配一个 int，用于存放最大值
    int* max_ptr = new int;
    *max_ptr = arr[0];  // 初始化为第一个元素

    for (int i = 1; i < len; i++) {
        if (arr[i] > *max_ptr) {
            *max_ptr = arr[i];
        }
    }
    return max_ptr;  // 调用者负责 delete
}

int main() {
    // 动态分配数组并初始化,c++11
    int* a = new int[5]{1, 2, 3, 4, 5};
    
    // 传入数组和长度
    int* max_val = find_max_dynamic(a, 5);
    
    cout << "最大值: " << *max_val << endl;  // 输出 5
    
    // 管理内存
    delete max_val;   // 先释放存放最大值的内存
    delete[] a;       // 再释放数组内存

    return 0;
}