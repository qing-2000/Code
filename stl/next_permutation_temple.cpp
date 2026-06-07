#include<iostream>
#include<algorithm>
#include<vector>
std::vector<int> arr;
void init(){
for(int i=0;i<3;i++){
        arr.push_back(i);
    }
}
void func(){
    do{
        for(auto i : arr ){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }while(std::next_permutation(arr.begin(),arr.end()));
    //生成字典序的下一个排列，如果没有下一个排列则返回 false。
    //pre_permutation生成上一个排列
}
int main(){
    init();
    func();
    return 0;
}