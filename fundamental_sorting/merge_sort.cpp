#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(vector<int> a){
    for(auto n:a)cout<<n<<" ";
    cout<<"\n";
}
// ==================== 合并函数 ====================
template<typename T>
void merge(std::vector<T>& arr, int left, int mid, int right) {
    // 1. 创建临时数组，存放合并结果
    std::vector<T> temp(right - left + 1);
    
    int i = left;       // 左半部分的起始索引
    int j = mid + 1;    // 右半部分的起始索引
    int k = 0;          // temp 数组的索引
    
    // 2. 两路归并：比较左右两半的当前元素，取较小的放入 temp
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    
    // 3. 把左半部分剩余的元素全部拷入 temp
    while (i <= mid)
        temp[k++] = arr[i++];
    
    // 4. 把右半部分剩余的元素全部拷入 temp
    while (j <= right)
        temp[k++] = arr[j++];
    
    // 5. 把排好序的 temp 拷回原数组的对应位置
    std::copy(temp.begin(), temp.end(), arr.begin() + left);
}

// ==================== 归并排序主函数 ====================
template<typename T>
void merge_sort(std::vector<T>& arr, int left, int right) {
    // 递归基：只有一个元素或空区间时，已经有序
    if (left >= right) return;
    
    // 分：计算中间位置
    int mid = left + (right - left) / 2;  // 防止 left+right 溢出
    
    // 治：递归排序左右两半
    merge_sort(arr, left, mid);       // 排序左半 [left, mid]
    merge_sort(arr, mid + 1, right);  // 排序右半 [mid+1, right]
    
    // 合：合并两个有序子数组
    merge(arr, left, mid, right);
}
int main(){
    vector<int> a={23945867,938746,99,7777,-23456432,-98765,-1,0};
    int len=a.size();
    merge_sort(a,0,len-1);
    print(a);
    return 0;
}