#include<iostream>
#include<utility>//引入pair
//找出数组中的最大值和最小值
using namespace std;
std::pair<int, int> MaxMin(int a[], int l, int r) {
    if (a == nullptr ){ cerr<<"数组为空。";exit(1); }
    if (l == r) return {a[l], a[l]};                    // 单个元素
    if (r - l == 1) {
        if (a[l] > a[r]) return {a[l], a[r]};
        else             return {a[r], a[l]};
    }
    int mid = l + (r - l) / 2;
    auto [maxL, minL] = MaxMin(a, l, mid);
    auto [maxR, minR] = MaxMin(a, mid + 1, r);
    return { std::max(maxL, maxR), std::min(minL, minR) };
}
int main(){
    int a[]={0,-9,6,11,3,7};
    //sizeof(a)/sizeof(a[0])
    auto num=MaxMin(a,0,sizeof(a)/sizeof(a[0])-1);
    int maxNum,minNum;
    tie(maxNum,minNum)=num;
    cout<<maxNum<<" "<<minNum;
    return 0;
}