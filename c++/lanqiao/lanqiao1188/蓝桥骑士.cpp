#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 10;
int ans[N]; // 原始数组
int lis[N]; // 用于维护 LIS 的候选值

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ans[i];
    }

    int len = 0; // 当前 LIS 的长度
    for (int i = 1; i <= n; i++) {
        // 使用二分查找找到第一个大于等于 ans[i] 的位置
        int left = 1, right = len, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (lis[mid] < ans[i]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        lis[left] = ans[i]; // 更新该位置的值
        if (left > len) len = left; // 如果找到了更长的位置，更新长度
    }

    cout << len << endl; // 输出 LIS 的长度
    return 0;
}