#include<iostream>
#include<vector>
using namespace std;
int main(){
int a,b,c;
cin>>a;
vector<int> results;
results.reserve(a);
while(a){
    cin>>b>>c;
    results.push_back(b+c);
    a--;
}
for(int i=0;i<results.size();i++){
    cout<<results[i]<<endl;
}
return 0;
}