#include<iostream>
#include<vector>
using namespace std;
int maxSum(vector<int> a){
    int Sum=0;
    for(auto n:a){
        if(Sum==0&&n<=0){
            ;
        }else if(Sum==0&&n>0){
            Sum+=n;
        }else{
            Sum=max(Sum+n,Sum);
        }
    }
    return Sum;
}
int main(){
    vector<int> a={-1,-2,-3,4,-9,0,9};
    int res=maxSum(a);
    cout<<res;
    return 0;
}