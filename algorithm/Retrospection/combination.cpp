#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define inf -1e9
//打印
void print(const vector<vector<int>> a){
    for(auto n:a){
        cout<<"{ ";
        for(auto i:n)cout<<i<<" ";
        cout<<"}\n";
    }

}
//core
void divideSet(vector<int> vset,int startIndex,vector<int>& subset,int divideNum,vector<vector<int>>& res){
    
    if(subset.size()==divideNum){
        res.emplace_back(subset);
        return ;
    }
    for(int i=startIndex;i<vset.size();i++){
        if(i>startIndex&&vset[i]==vset[i-1])continue;
        subset.emplace_back(vset[i]);
        divideSet(vset,i+1,subset,divideNum,res);
        subset.pop_back();
    }
    
}
//pre
void pre(vector<int> a,int divideNum){
    sort(a.begin(),a.end());
    vector<int> subset;
    vector<vector<int>> res;
    divideSet(a,0,subset,divideNum,res);
    print(res);
}
int main(){
    vector<int> a={0,1,2,3};
    int targetNum=1;
    pre(a,targetNum);
    return 0;
}