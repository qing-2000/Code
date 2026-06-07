#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//不建议原生数组，坍缩为指针使用sizeof风格处理数组长度失效，需要直接将数组长度作为参数
int findNum(vector<int>& biscuit, vector<int>& appetite) {
    sort(biscuit.begin(), biscuit.end());   // 饼干尺寸升序
    sort(appetite.begin(), appetite.end()); // 孩子胃口升序
    int i = 0, j = 0, count = 0;
    while (i < biscuit.size() && j < appetite.size()) {
        if (biscuit[i] >= appetite[j]) { // 当前饼干能满足当前孩子
            count++;
            i++;
            j++;
        } else {
            i++; // 饼干太小，换下一个更大的饼干
        }
    }
    return count;
}

int main() {
    vector<int> biscuit = {1, 2, 3, 4, 5};
    vector<int> appetite = {2, 3, 4, 5, 6};
    int num = findNum(biscuit, appetite);
    cout << num << endl; // 输出 4（因为最大饼干 5 无法满足胃口 6）
    return 0;
}