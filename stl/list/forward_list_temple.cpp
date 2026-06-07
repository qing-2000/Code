/*
单向链表：

std::forward_list 是单向链表，只能从前往后遍历，不能反向遍历。
由于其单向链表的结构，插入和删除操作在已知位置的情况下非常高效（O(1) 复杂度）。
低内存开销：

与 std::list 相比，std::forward_list 只需要一个指向下一个节点的指针，节省了内存。
不支持随机访问：

不支持通过索引访问元素，不能使用 operator[] 或 at 方法，只能通过迭代器进行访问。

关键迭代器：获取关键位置。begin() 指向首个元素，end() 指向末尾之后，特别的 before_begin() 
返回指向第一个元素之前的迭代器，这是所有“_after”操作的基础。

容量查询：empty() 检查是否为空。它没有 size() 成员函数，这是出于性能考量，
如需大小请用 std::distance(fl.begin(), fl.end())。

“_after”系列修改器：在指定位置之后操作。insert_after(pos, value)，emplace_after(pos, args...)，
erase_after(pos)。splice_after(pos, other_list) 移动另一个链表的元素。

前置操作：push_front(value), emplace_front(args...), pop_front()。

链表专有操作：remove(value), remove_if(predicate), reverse(), sort(), unique()。

通用功能：clear(), swap(other_list), merge(other_list)。

*/
#include <iostream>
#include <forward_list>
//唯一一个没有size的容器
int main() {
    // 创建一个空的 forward_list
    std::forward_list<int> fl;

    // 在列表前端添加元素
    fl.push_front(10);
    fl.push_front(20);
    fl.push_front(30);

    // 遍历 forward_list 并输出元素
    for (auto it = fl.begin(); it != fl.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 输出结果：30 20 10

    return 0;
}