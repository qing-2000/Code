#include <iostream>
#include <memory>
using namespace std;
struct B;  // 前置声明
struct A {
    shared_ptr<B> b_ptr;
    ~A() { cout << "A 被销毁\n"; }
};
struct B {
    weak_ptr<A> a_ptr;  // ← 换成 weak_ptr，不增加引用计数
    ~B() { cout << "B 被销毁\n"; }
};
int main() {
    auto a = make_shared<A>();
    auto b = make_shared<B>();
    
    a->b_ptr = b;  // b 引用计数 = 2
    b->a_ptr = a;  // weak_ptr 不增加计数，a 引用计数仍是 1
    
    // main 结束：
    // a 析构 → a 引用计数变 0 → A 对象销毁 → A::b_ptr 析构 → b 引用计数减 1
    // b 析构 → b 引用计数变 0 → B 对象销毁
    return 0;
}