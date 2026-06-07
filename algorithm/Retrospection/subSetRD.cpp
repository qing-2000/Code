//查找所有子集(有重复元素)
#include<iostream>
#include<vector>
#include<algorithm>
//#include<unordered_map>非无法排序条件下不适用hash
using namespace std;

//打印
void print(vector<vector<int>> subset){
    
    for(auto n: subset){
        cout<<"{ ";
        for(auto a:n)cout<<a<<" ";
        cout<<"}"<<"\n";
    }
    
}
//去重

//core
vector<vector<int>> findSubSet(vector<int> arr,int startIndex,vector<int>& Path,vector<vector<int>>& res){
    //将子集加入结果数组
    res.emplace_back(Path);
    //
    for(int i=startIndex;i<arr.size();i++){
        //剪枝：同层去重
        if(i>startIndex&&arr[i-1]==arr[i])continue;
        Path.emplace_back(arr[i]);
        findSubSet(arr,i+1,Path,res);
        Path.pop_back();
    }
    return res;
}

//预处理
vector<vector<int>> preProcess(vector<int>& vset){
    sort(vset.begin(),vset.end());
    vector<int> Path;//存储路径
    vector<vector<int>> res;//存储子集
    return findSubSet(vset,0,Path,res);
} 
int main(){
    vector<int> a={2,1,2};
    print(preProcess(a));
    return 0;
}