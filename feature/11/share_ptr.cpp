#include<iostream>
#include<memory>
using namespace std;
//修改i这块空间的值
void foo(shared_ptr<int> i){
    (*i)++;
}
int main(){
    auto pointer=make_shared<int>(10);
    foo(pointer);
    //use_count获取共享这块空间的指针的数量
    cout<<*pointer<<" "<<pointer.use_count();

    //增加共享指针
    auto pointer2=pointer;
    foo(pointer2);
    auto pointer3=pointer;
    foo(pointer3);
    cout<<"\n"<<pointer.use_count()<<"\n";

    //share_ptr.get（）,获取原始指针
    //用途：当你需要把指针传给只接受裸指针的C风格接口时：
    //void legacy_api(int* p); 
    //legacy_api(pointer.get());     // 安全传递，引用计数不变
    //输出pointer的原始地址，可用*解引用得出值
    cout<<pointer.get()<<"\n";

    //reset,重置share指针，计数-1
    //作用：让当前shared_ptr放弃对原对象的管理，引用计数减1。它可以接受一个可选的裸指针参数，\
    转为管理新对象。

    //三种用法：不带参数，带一个新裸指针，多个share共享时

    //不带参数
    auto test = std::make_shared<int>(42);  // 引用计数 = 1
    test.reset();                           
    // 放弃所有权，引用计数变为 0，int 被释放，\
    现在 temp 是空的（temp == nullptr）
    
    //带一个新的裸指针
    auto sp = std::make_shared<int>(42);  // 管理 int(42)
    sp.reset(new int(100));               // 释放原来的 int(42)，开始管理新的 int(100)

    //多个share共享
    auto p1 = std::make_shared<int>(10);  // 引用计数 = 1
    auto p2 = p1;                         // 引用计数 = 2
    p1.reset();                           
    // p1 放弃所有权，p1变为nullptr ，引用计数变成 1，\
    p2 仍然指向那块内存，数据还在,p1解引用必定崩溃，\
    只有计数为0时这些指针才销毁,此时p1与计数控制块脱离无法获取数量
    cout<<"p1执行reset后的共享指针数量为："<<p2.use_count()<<"\n";
    return 0;
}