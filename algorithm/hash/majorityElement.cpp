#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
//数组中出现最多的数字
int majorityElement(vector<int> &a){
    if(a.size()<=0)return -1;
    unordered_map<int,int> um(a.size());
    int res=a[0],maxNum=0;
    for(auto n:a){
        um[n]++;
        if(um[n]>maxNum){
            maxNum=um[n];
            res=n;
        }
    }
    return res;
}
int main(){
    vector<int> arr={1,2,3,4,5,6,7,3,3,3,3,9};
    int ans=majorityElement(arr);
    cout<<ans;
    return 0;
}