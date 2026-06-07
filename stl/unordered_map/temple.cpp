/*
unordered_map 是一个关联容器，它存储了键值对（key-value pairs），
其中每个键（key）都是唯一的。unordered_map 使用哈希表来存储元素，
这使得它在查找、插入和删除操作中具有平均常数时间复杂度。

find(key)	迭代器。找到则指向键值对，否则为 end()	if (auto it = m.find(k); it != m.end())	最常用，不改变容器
count(key)	size_t。找到返回 1，否则 0	if (m.count(k))	简单存在性检查
contains(key)	bool。存在返回 true	if (m.contains(k))	✅ C++20 起推荐，语义最清晰


#include <unordered_map>

std::unordered_map<key_type, value_type> map_name;
key_type 是键的类型。
value_type 是值的类型。

构造函数

// 默认构造
std::unordered_map<int, std::string> myMap;

// 构造并初始化
std::unordered_map<int, std::string> myMap = {{1, "one"}, {2, "two"}};

// 构造并指定初始容量
std::unordered_map<int, std::string> myMap(10);

// 构造并复制另一个 unordered_map
std::unordered_map<int, std::string> anotherMap = myMap;
基本操作
插入元素:

myMap.insert({3, "three"});
访问元素:

std::string value = myMap[1]; // 获取键为1的值
删除元素:

myMap.erase(1); // 删除键为1的元素
查找元素:

auto it = myMap.find(2); // 查找键为2的元素
if (it != myMap.end()) {
    std::cout << "Found: " << it->second << std::endl;
}
*/
#include <iostream>
#include <unordered_map>

int main() {
    // 创建一个 unordered_map，键为 int，值为 string
    std::unordered_map<int, std::string> myMap;

    // 插入一些键值对
    myMap[1] = "one";
    myMap[2] = "two";
    myMap[3] = "three";

    // 打印所有元素
    for (const auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    // 访问特定键的值
    std::cout << "Value for key 2: " << myMap[2] << std::endl;

    //查找
    //c++20 if (myMap.contains(2)) {
    //    auto it = myMap.find(2);
    //    std::cout << it->first;
    //}
    //通用查找
    if (myMap.find(2) != myMap.end()) {
        std::cout << "Found: " << 2 << " -> " << myMap[2] << std::endl;
    } else {
        std::cout << 2 << " not found" << std::endl;
    }

    // 删除键为1的元素
    myMap.erase(1);

    // 再次打印所有元素
    std::cout << "After erasing key 1:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    return 0;
}