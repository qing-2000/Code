/*
C++11 标准引入了 <array> 头文件，它提供了一种固定大小的数组容器，与 C 语言中的数组相比，具有更好的类型安全和内存管理特性。
std::array 是 C++ 标准库中的一个模板类，它定义在 <array> 头文件中。std::array 模板类提供了一个固定大小的数组，
其大小在编译时确定，并且不允许动态改变。

类型安全：std::array 强制类型检查，避免了 C 语言数组的类型不安全问题。
固定大小：数组的大小在编译时确定，不能在运行时改变。
内存连续：std::array 的元素在内存中是连续存储的，这使得它可以高效地访问元素。
标准容器：std::array 提供了与 std::vector 类似的接口，如 size(), at(), front(), back() 等。

std::array 保存在栈内存中，
相比堆内存中的 std::vector，我们能够灵活的访问这里面的元素，从而获得更高的性能。

std::array 会在编译时创建一个固定大小的数组，std::array 不能够被隐式的转换成指针，
使用 std::array只需指定其类型和大小

*/
#include<iostream>
#include<array>
using namespace std;

void foo(int* p,int len){
    return;
}

int main(){
    //定义array<type,size> arrayName;
    array<int,5> myarr={1,2,3,4,5};
    
    //.at(x)通过索引x访问元素,修改元素
    cout<<myarr.at(2)<<"\n";

    //.size()获取数组大小
    cout<<".size()数组大小为："<<myarr.size()<<"\n";

    //.front()获取数组第一个元素
    cout<<myarr.front()<<"\n";

    //.back()获取最后一个元素
    cout<<myarr.back()<<"\n";

    //.fiil(x)将数组所有元素填充为x
    myarr.fill(100);
    cout<<".fill(100)后的数组元素：";
    for(int i=0;i<5;i++)cout<<myarr[i]<<" ";
    cout<<"\n";

    //.swap(arrayName)交换两个数组的元素
    std::array<int, 3> arr1 = {1, 2, 3};
    cout<<"交换前的arr1：";
    for(int i=0;i<3;i++)cout<<arr1[i]<<" ";
    cout<<"\n";
    std::array<int, 3> arr2 = {4, 5, 6};
    arr1.swap(arr2);
    cout<<"交换后的arr1：";
    for(int i=0;i<3;i++)cout<<arr1[i]<<" ";
    cout<<"\n";

    //.data()指向数组空间的指针,显式、安全、统一的途径来获取底层连续内存的首地址

    //避免数组退化指针缺少大小，能与c api交互
    //void legacy_c_function(const int* p, size_t n);
    //legacy_c_function(arr.data(), arr.size());  // 明确表达“我就是要指针”
    int* pre=myarr.data();
    cout<<"用指针显式调用数组："<<pre[0]<<"\n";

    //c风格传参
    foo(&myarr[0],myarr.size());//等同于foo(myarr.data(),myarr.size());

    return 0;
}