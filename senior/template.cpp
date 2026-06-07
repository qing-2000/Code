#include<iostream>
template<typename T>//自定义模板
T add(T a,T b){
    return a+b; 
}
int main(){
    int a=1,b=2;
    std::cout<<"a+b="<<add(a,b)<<std::endl;
    return 0;
}