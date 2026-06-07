/*
<set> 提供了高效的元素查找、插入和删除操作。它是基于红黑树实现的，因此具有对数时间复杂度的查找、插入和删除性能。

<set> 容器中存储的元素类型必须满足以下条件：

元素类型必须可以比较大小。
元素类型必须可以被复制和赋值。

常用操作
insert(元素): 插入一个元素。
erase(元素): 删除一个元素。
find(元素): 查找一个元素。
size(): 返回容器中元素的数量。
empty(): 检查容器是否为空。
*/
#include<iostream>
#include<set>
using namespace std;
int main(){
    // 声明一个整型 set 容器
    std::set<int> mySet;

    // 插入元素
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.insert(40);

    // 输出 set 中的元素
    std::cout << "Set contains: ";
    for (int num : mySet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 查找元素
    if (mySet.find(20) != mySet.end()) {
        std::cout << "20 is in the set." << std::endl;
    } else {
        std::cout << "20 is not in the set." << std::endl;
    }

    // 删除元素
    mySet.erase(20);

    // 再次输出 set 中的元素
    std::cout << "After erasing 20, set contains: ";
    for (int num : mySet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 检查 set 是否为空
    if (mySet.empty()) {
        std::cout << "The set is empty." << std::endl;
    } else {
        std::cout << "The set is not empty." << std::endl;
    }

    // 输出 set 中元素的数量
    std::cout << "The set contains " << mySet.size() << " elements." << std::endl;
    return 0;
}