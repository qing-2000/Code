//sb题目，超时
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct Triple{
    int a,b,c;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Triple> ans;
    ans.reserve(200000);

    int limit = sqrt(N);

    for(int m=2;m<=limit;m++){
        for(int n=1;n<m;n++){

            if((m-n)%2==0) continue;
            if(__gcd(m,n)!=1) continue;

            int a = m*m - n*n;
            int b = 2*m*n;
            int c = m*m + n*n;

            if(c > N) continue;
            if(a>b) swap(a,b);

            for(int k=1;k*c<=N;k++){
                ans.push_back({k*a,k*b,k*c});
            }
        }
    }

    sort(ans.begin(),ans.end(),[](const Triple& x,const Triple& y){
        if(x.a!=y.a) return x.a<y.a;
        if(x.b!=y.b) return x.b<y.b;
        return x.c<y.c;
    });

    for(size_t i=0;i<ans.size();i++){
        cout<<ans[i].a<<" "<<ans[i].b<<" "<<ans[i].c;
        if(i+1<ans.size()) cout<<" ";
    }

    return 0;
}