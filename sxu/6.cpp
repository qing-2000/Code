#include<bits/stdc++.h>
using namespace std;
int func(int a,int b) {
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));
    for (int i = 0; i <= a; i++) dp[i][1] = 1;
    
    for (int i = 0; i <= a; i++) {
        for (int j = 2; j <= b; j++) {
            dp[i][j] = dp[i][j-1];
            if (i >= j) dp[i][j] += dp[i-j][j];
        }
    }
    
    return dp[a][b];
}
/*
m=7,n=3
0,0,7
0,1,6
0,2,5
0,3,4
1,1,5
1,2,4
1,3,3
2,2,3
*/
int main(){
    int t,m,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>m>>n;
        cout<<func(m,n)<<endl;
    }
    return 0;
}