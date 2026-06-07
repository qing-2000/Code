//交换零钱，完全背包问题
#include<iostream>
#include<vector>
#include<climits>//引入INT_MAX
using namespace std;
int fun(vector<int> e,int tar){
    int len=e.size();
    static int inf=1e9;
    vector<vector<int>> dp(len+1, vector<int>(tar + 1, inf));
    for(int i=0;i<=len;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=len;i++){
        for(int j=1;j<=tar;j++){
            //不选
            dp[i][j]=dp[i-1][j];
            //选
            if(j>=e[i-1]&&dp[i][j-e[i-1]]!=inf)dp[i][j]=min(dp[i][j],1+dp[i][j-e[i-1]]);
        }
    }
    return dp[len][tar]==inf?-1:dp[len][tar];
}
int main(){
    vector<int> Exchange={1,7,10};
    int res=0,target=15;
    res=fun(Exchange,target);
    cout<<res;
    return 0;
}