#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> ans;
    for(int i=100;i<=n;i++){
        int g=i%10;
        int s=(i/10)%10;
        int b=i/100;
        if(g*g*g+s*s*s+b*b*b==i)ans.emplace_back(i);
    }
    for(auto&n:ans)cout<<n<<endl;
  
    return 0;
}