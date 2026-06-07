/*
<list> 是 C++ 标准模板库（STL）中的一个序列容器，它允许在容器的任意位置快速插入和删除元素。
与数组或向量（<vector>）不同，<list> 不需要在创建时指定大小，
并且可以在任何位置添加或删除元素，而不需要重新分配内存。

语法
以下是 <list> 容器的一些基本操作：

包含头文件：#include <list>
声明列表：std::list<T> mylist;，其中 T 是存储在列表中的元素类型。
插入元素：mylist.push_back(value);
删除元素：mylist.pop_back(); 或 mylist.erase(iterator);
访问元素：mylist.front(); 和 mylist.back();
遍历列表：使用迭代器 for (auto it = mylist.begin(); it != mylist.end(); ++it)
特点
双向迭代：<list> 提供了双向迭代器，可以向前和向后遍历元素。
动态大小：与数组不同，<list> 的大小可以动态变化，不需要预先分配固定大小的内存。
快速插入和删除：可以在列表的任何位置快速插入或删除元素，而不需要像向量那样移动大量元素。
*/
#include<iostream>
#include<list>
using namespace std;
void print(list<int> lis){
    list<int>::iterator it=lis.begin();
    for(it;it!=lis.end();it++) cout<<*it<<" ";
    cout<<"\n";
}
int main(){
    list<int> lis(10);
    
    //.push_front在头插入
    lis.push_front(1);
    
    //.push_back()在尾插入
    lis.push_back(-1);

    list<int>::iterator it=lis.begin();
    //.insert(iterator,val)在指定位置插入
    lis.insert(it,100);

    //.size()获取大小
    //.clear()清空
    //.empty()是否为空
    //.front()返回第一个，.back()返回最后一个
    
    print(lis);

    //.sort()升序
    lis.sort();
    print(lis);
    // 降序排序
    lis.sort(std::greater<int>());
    print(lis);

    //.erase(iterator)删除指定位置，(iterator.begin(),iterator.end())
    lis.erase(it);

    //.remove(x)删除列表中的所有x
    lis.push_back(100);
    lis.push_back(100);
    print(lis);
    lis.remove(100);
    print(lis);


    //.merge(list2)合并两个链表，合并后list2为空
    return 0;
}