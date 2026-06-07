#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <typeinfo>         //typeid
#include <initializer_list> //c++11初始化列表
#include <tuple>            //c++17结构化绑定
#include <type_traits>   //is_integral编译期常量
using namespace std;
class MagicFoo
{
public:
    std::vector<int> vec;
    MagicFoo(initializer_list<int> list)
    {
        for (initializer_list<int>::iterator it = list.begin(); it != list.end(); it++)
            vec.emplace_back(*it);
    }
};

// c++17结构化绑定示例
std::tuple<int, double, std::string> f()
{
    return std::make_tuple(1, 2.3, "456");
}

// c++11
template <typename T, typename U>
// 尾返回类型（trailing return type），利用 auto 关键字将返回类型后置：
// c++11
auto add2(T x, U y) -> decltype(x + y)
{
    return x + y;
}

template <typename T, typename U>
// c++14
auto add3(T x, U y)
{
    return x + y;
}

//c++14,带（）推导出 T&（引用类型）用于修改全局变量；不带（）推导出变量的声明类型 T。
int global_x = 10;
decltype(auto) get_ref_good()
{
    return (global_x);
}

//c++17 if constexpr
//将表达式或函数编译为常量结果，提高效率
template<typename T>
auto print_type_info(const T& t){
    // 使用三元运算符 + decltype，让编译器自动决定公共类型
    return std::is_integral<T>::value ? t + 1 : t + 0.1;
}

int main()
{
    vector<int> v;
    v.emplace_back(1);
    v.emplace_back(2);
    v.emplace_back(3);
    v.emplace_back(4);
    // if/switch变量声明强化,允许内部声明变量
    // 最大好处是作用域控制：让辅助变量仅在条件判断和分支中存活，
    // 抽身即消，避免污染外部空间，让代码更安全、更简洁。
    if (auto it = find(v.begin(), v.end(), 3); it != v.end())//find需要algorithm
    {
        *it = 4;
    }

    // initializer_listl列表初始化
    MagicFoo magicfoo = {1, 2, 3, 4, 5};
    cout << "magicfoo:";
    for (auto it = magicfoo.vec.begin(); it != magicfoo.vec.end(); it++)
        cout << *it << " ";
    cout << "\n";

    // tuple结构化绑定c++17
    auto [x, y, z] = f();
    cout << "结构化绑定示例：";
    cout << x << " " << y << " " << z << "\n";

    // auto,decltype c++11开始,类型推导
    // decltype 泛型编程中推导函数的返回值（后置返回类型）
    /*
        template <typename T, typename U>
            auto add(T&& t, U&& u) -> decltype(t + u) {
                return t + u;
        }
    */
    // 模板元编程中配合 std::is_same 在编译期检查类型
    /*
    template <typename T>
     void process(T val) {
         if constexpr (std::is_same<decltype(val), int>::value) {
             // 整数分支
         } else {
             // 其他分支
         }
     }
    */
    // 获取 lambda 表达式的匿名类型（无法手写类型名）
    /*
    auto lambda = [](int x) { return x * 2; };
    std::function<decltype(lambda)> f = lambda; // 用 decltype 捕获其类型
    // 或者更简洁：auto f = lambda;
    */
    // 保持值类别和 CV 限定符（与 auto 的重要区别）
    /*
    const int x = 5;
    auto a = x;        // a 是 int，丢失了 const
    decltype(x) b = x; // b 是 const int，完整保留
    */
    auto i = 5;
    auto d = 3.3;
    decltype(i + d) x = i + d;
    cout << "i的类型是：" << typeid(i).name() << "\n";

    // 验证auto，dectltype是否自动推导
    //  测试1：整数 + 整数 → 整数
    std::cout << "add2(3, 4)   = " << add2(3, 4)
              << " (类型: " << typeid(add2(3, 4)).name() << ")\n";
    std::cout << "add3(3, 4)   = " << add3(3, 4)
              << " (类型: " << typeid(add3(3, 4)).name() << ")\n\n";

    // 测试2：整数 + 浮点 → 浮点
    std::cout << "add2(3, 2.5) = " << add2(3, 2.5)
              << " (类型: " << typeid(add2(3, 2.5)).name() << ")\n";
    std::cout << "add3(3, 2.5) = " << add3(3, 2.5)
              << " (类型: " << typeid(add3(3, 2.5)).name() << ")\n\n";

    // 测试3：字符串 + 字符串 → 字符串（必须有一方是 std::string）
    std::string s = "Hello, ";
    std::cout << "add2(s, \"World!\") = " << add2(s, "World!")
              << " (类型: " << typeid(add2(s, "World!")).name() << ")\n";
    std::cout << "add3(s, \"World!\") = " << add3(s, "World!")
              << " (类型: " << typeid(add3(s, "World!")).name() << ")\n\n";

    // 测试4：两个 C 字符串相加 → 编译错误！
    // add2("Hello", "World");  // ❌ 错误：两个指针不能相加

    // c++14
    // decltype(auto) 主要用于对转发函数或封装的返回类型进行推导；
    // 还能原封不动地保留表达式的“引用性”和“常量性”。
    decltype(auto) result = get_ref_good();
    result = 20;                     // 修改了 global_x
    std::cout << global_x << '\n';   // 输出 20

    //c++11 constexpr它将表达式或函数编译为常量结果
    //if constexpr 控制流
    //c++17加入到if语句中，让代码在编译时就完成分支判断，让程序效率更高
    //返回6
    std::cout << print_type_info(5) << "\n";
    //返回3.24
    std::cout << print_type_info(3.14) << "\n";

    //c++11 区间for循环
    cout<<"v容器中的元素有：";
    for(auto n: v){
        cout<<n<<" ";
    }
    cout<< "\n";
    
    return 0;
}