#include<iostream>
using namespace std;
//c++11引入,允许任意个数、任意类别的模板参数，同时也不需要在定义时将参数的个数固定。
//template<typename... Ts> class Magic;

//如果不希望产生的模板参数个数为 0，可以手动的定义至少一个模板参数：
//template<typename Require, typename... Args> class Magic;

template<typename... Ts>
void magic(Ts... args) {
    //使用 sizeof... 来计算参数的个数
    std::cout << sizeof...(args) << "\n";
}


int main(){
    magic();
    magic(1);
    magic(1,"goodbye world");
    return 0;
}