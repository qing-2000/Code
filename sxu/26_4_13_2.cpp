#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> ans;

	for(int i=0;i<n;i++)cin>>a[i];
	//for(int i=0;i<n;i++)cout<<a[i]<<endl;
	for(int i=0;i<n;i++){
		
		if(i==0)continue;
		if(i==n-1) break;
		bool f1=a[i]>a[i-1];
		bool f2=a[i]>a[i+1];

		if(f1&&f2){
			ans.push_back(a[i]);
			//cout<<a[i]<<endl;
		}
		
		
		//if(i==n-1&&a[i]>a[i-1]) ans.push_back(a[i]);
	}
	long long sum=0;
	for(int i=0;i<ans.size();i++)sum+=ans[i];
	cout<<sum;
	return 0;
}