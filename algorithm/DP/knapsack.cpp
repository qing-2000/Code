#include<iostream>
#include<vector>
using namespace std;
int knapsack(vector<int> v,vector<int> w,int target){
    int col=w.size();
    int row=v.size();
    vector<vector<int>> dp(row,vector<int>(target+1,0));
    for(int i=1;i<row;i++){
        for(int j=1;j<=target;j++){
            //不选
            dp[i][j]=dp[i-1][j];
            //选,同一行就是完全背包，上一行就是01背包
            if(j>=w[i])dp[i][j]=max(dp[i][j],v[i]+dp[i][j-w[i]]);
            //if(j>=w[i])dp[i][j]=max(dp[i][j],v[i]+dp[i-1][j-w[i]]);
        }
    }
    return dp[row-1][target];
}
int main(){
    vector<int> value={0,1,6,18,22,28};
    vector<int> weight={0,1,2,5,6,7};
    int target=11;
    int res=knapsack(value,weight,target);
    cout<<res;
    return 0;
}