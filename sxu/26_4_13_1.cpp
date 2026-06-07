#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,d;
	long long l,r;
	cin>>n;
	cin>>d;
    if(n%d==0){
		cout<<n;
		return 0;
	}
	l=n-1;
	r=n+1;
    vector<long long int> ans;
	while(1){
		bool templ=(l%d==0);
		bool tempr=(r%d==0);
        if(templ) ans.push_back(l);
        if(tempr) ans.push_back(r);
		if(templ||tempr) break;
		l--;
		r++;
	}
	long long cal=n-l;
	long long car=r-n;
    sort(ans.begin(),ans.end());
    //for(auto&n:ans)cout<<n<<"\n";
    //cout<<ans.size()<<"\n";
    if(!ans.empty()){
        cout<<ans[0];
        if(ans.size()>1) {
        cout<<"\n";
        cout<<ans[1];
        }
    }
	return 0;
}