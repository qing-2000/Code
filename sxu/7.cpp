#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    double k=1.0,ans=1.0;
    for(int i=1;i<=n;i++){
        k/=i;//通过/代替阶乘计算
        ans+=k;
    }
    printf("%.10f",ans);
    return 0;
}