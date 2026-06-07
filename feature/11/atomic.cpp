// #include<iostream>
// #include<thread>
// using namespace std;
// int main(){
//     int a = 0;
//     //如果一个变量被声明为 volatile，编译器就必须每次从内存中重新读取或写入，不能做任何省略或重排。
//     //不能用于多线程同步
//     volatile int flag = 0;

//     std::thread t1([&]() {
//         while (flag != 1);
//         int b = a;
//         std::cout << "b = " << b << std::endl;
//     });

//     std::thread t2([&]() {
//         a = 5;
//         flag = 1;
//     });

//     t1.join();
//     t2.join();

//     return 0;
// }
#include <atomic>
#include <thread>
#include <iostream>
#include <vector>
std::atomic<int> count = {0};
struct A
{
    float x;
    int y;
    long long z;
};
int main()
{
    /*
    fetch_add 是 std::atomic 的成员函数，定义在 <atomic> 头文件中。它执行原子加法操作，将指定的值加到原子变量上，并返回修改前的值（或修改后的值，取决于具体重载）。

    fetch_add(1) 就是原子地将原子变量加 1，类似于 ++counter，但保证多线程安全。

    它可以使用不同的内存序（如 std::memory_order_relaxed），以在性能与同步需求之间平衡。
    */
    std::thread t1([]()
                   { count.fetch_add(1); });
    std::thread t2([]()
                   {
                       count++;    // 等价于 fetch_add
                       count += 1; // 等价于 fetch_add
                   });
    std::atomic<A> a;
    t1.join();
    t2.join();
    std::cout << count << std::endl;                 // 输出3
    /*
    
    std::boolalpha 定义在 <ios> 或 <iostream> 中（通常包含 <iostream> 就能用）。它是一个 I/O 操纵符，用于控制 bool 值的输出格式：

    默认情况下，cout << true; 输出 1，cout << false; 输出 0。

    使用 std::boolalpha 后，输出变为 true 或 false（字符串形式）。
    
    */
    std::cout << std::boolalpha << a.is_lock_free()<<"\n"; // 输出false

    std::atomic<int> counter = {0};
    std::vector<std::thread> vt;
    for (int i = 0; i < 100; ++i)
    {
        vt.emplace_back([&]()
                        { counter.fetch_add(1, std::memory_order_relaxed); });
    }

    for (auto &t : vt)
    {
        t.join();
    }
    std::cout << "current counter:" << counter << std::endl;
    return 0;
}