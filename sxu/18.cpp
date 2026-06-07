#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a;
    bool flag=true;
    for(int i=n;i<=m;i++){
        if(i==1) continue;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0) {
                flag=false;
                break;
            }
        }
        if(flag) a.push_back(i);
        flag=true;
    }
    int count=0;
    for(int i=0;i<a.size();i++){
        if(count>7&&count%8==0)cout<<endl;
        cout<<a[i]<<" ";
        count+=1;
    }
    return 0;
}