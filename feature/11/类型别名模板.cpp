#include<iostream>
#include<vector>

template<typename T, typename U>
class MagicType {
public:
    T dark;
    U magic;
};


//模板T，T作为入口将值赋予vector容器的类型
template<typename T>
using TrueDarkMagic = MagicType<std::vector<T>, std::string>;



using namespace std;
int func(void*){
    return 777;
}

//c++11 using 替代 typedef 防止歧义
typedef int (*process)(void*);
using NewProcess=int(*)(void*);

int main(){
    //func隐式函数地址入口，效果通&func显示函数地址入口，同func（void）直接调用函数结果相同
    process m1=func;
    NewProcess m2=func;
    //arr 是一个数组，有 2 个元素，每个元素是一个函数指针，它指向的函数返回 int，接受 void* 参数。
    int (*arr[2])(void*) = {m1,m2};
    cout<<"typedef:"<<arr[0](nullptr)<<"\n";
    cout<<"using:"<<arr[1](nullptr)<<"\n";

    TrueDarkMagic<bool> you; // 等价于 MagicType<std::vector<bool>, std::string> you;
    you.dark = std::vector<bool>{true, false, true};

    for(auto n:you.dark) cout<<n<<"\n";
    you.magic = "Hello, World!";
    
    std::cout << you.magic << std::endl; // 输出 Hello, World!
    return 0;
}