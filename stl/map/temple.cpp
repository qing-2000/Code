/*
在 C++ 中，<map> 是标准模板库（STL）的一部分，它提供了一种关联容器，用于存储键值对（key-value pairs）。

map 容器中的元素是按照键的顺序自动排序的，这使得它非常适合需要快速查找和有序数据的场景。

定义和特性
键值对：map 存储的是键值对，其中每个键都是唯一的。
排序：map 中的元素按照键的顺序自动排序，通常是升序。
唯一性：每个键在 map 中只能出现一次。
双向迭代器：map 提供了双向迭代器，可以向前和向后遍历元素。

基本语法
包含头文件:

#include <map>
声明 map 容器:
std::map<key_type, value_type> myMap;
key_type 是键的类型。
value_type 是值的类型。

插入元素:
myMap[key] = value;

访问元素:
value = myMap[key];

遍历 map:
for (std::map<key_type, value_type>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
    std::cout << it->first << " => " << it->second << std::endl;
}

C++11 及以上标准，遍历部分可以简化为范围 for 循环，代码更简洁：
for (auto &p : m) {
    std::cout << p.first << " : " << p.second << std::endl;
}

删除元素:
myMap.erase(key);

清空 map:
myMap.clear();

获取 map 的大小:
size_t size = myMap.size();

其他方法：
myMap.empty();      // 是否为空
myMap.count("Bob"); // key 是否存在（返回 0 或 1）

自定义排序，默认升序排序，可以用 std::greater 或自定义比较函数：
std::map<int, std::string, std::greater<int>> m;  // 降序
*/
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> scores;

    // 插入
    scores["Alice"] = 90;
    scores["Bob"] = 85;
    scores.insert({"Charlie", 92});

    // 遍历
    for (auto &p : scores) {
        std::cout << p.first << " => " << p.second << std::endl;
    }

    // 查找
    auto it = scores.find("Bob");
    if (it != scores.end()) {
        std::cout << "Bob's score: " << it->second << std::endl;
    }

    // 删除
    scores.erase("Alice");

    std::cout << "Size: " << scores.size() << std::endl;

    return 0;
}