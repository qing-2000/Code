#include <iostream>
#include <optional>  // C++17 新增的特性
#include <variant>   // C++17 新增的特性

int main() {
    // 测试 std::optional (C++17)
    std::optional<int> opt = 42;
    if (opt) {
        std::cout << "optional test: " << *opt << std::endl;
    }
    
    // 测试结构化绑定 (C++17)
    std::pair<int, std::string> p = {1, "hello"};
    auto [num, str] = p;
    std::cout << "structured binding: " << num << ", " << str << std::endl;
    
    // 测试 if 初始化 (C++17)
    if (int x = 10; x > 5) {
        std::cout << "if with init: x = " << x << std::endl;
    }
    
    return 0;
}