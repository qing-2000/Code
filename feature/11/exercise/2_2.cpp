/*
尝试用折叠表达式实现用于计算均值的函数，传入允许任意参数。
*/

#include<iostream>
template<typename... T>
auto sum(T... args){
    return (args+...);
}

using namespace std;
int main(){
    cout<<sum(1,2,3,4,5,6,7,8.9,9,10);
    return 0;
}