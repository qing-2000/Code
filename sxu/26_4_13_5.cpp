#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    vector<int> ans={a,b,c};
    sort(ans.begin(),ans.end());
    int mi=ans[0], mid=ans[1], ma=ans[2];
    if(mi+mid>ma){
        if(mi*mi+mid*mid==ma*ma) cout<<"Right triangle\n";
        if(mi*mi+mid*mid>ma*ma) cout<<"Acute triangle\n";
        if(mi*mi+mid*mid<ma*ma) cout<<"Obtuse triangle\n";
        if(mi==mid || mid==ma) cout<<"Isosceles triangle\n";
        if(mi==mid && mid==ma) cout<<"Equilateral triangle\n";
    } else {
        cout<<"Not triangle\n";
    }
    return 0;
}