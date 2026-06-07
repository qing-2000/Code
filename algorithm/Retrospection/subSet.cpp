//查找所有子集（无重复元素）

#include<iostream>
#include<vector>
using namespace std;
//打印
void print(vector<int> subset){
    cout<<"{ ";
    for(auto n: subset){
        cout<<n<<" ";
    }
    cout<<"}"<<"\n";
}
//
void findsubset(vector<int> arr,vector<int>& subset,int startIndex){
    //打印子集
    print(subset);
    //core
    for(int i=startIndex;i<arr.size();i++){
        //母集元素加入子集
        subset.emplace_back(arr[i]);
        //递归向前增加子集
        findsubset(arr,subset,i+1);
        //回溯
        subset.pop_back();
    }
}
//预处理(额外分配空间)
void preProcess(vector<int> vset){
    vector<int> subset;
    findsubset(vset,subset,0);
}
int main(){
    vector<int> vset={1,1,3};
    preProcess(vset);
    return 0;
}