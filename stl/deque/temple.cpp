/*
<deque> 的全称是 "double-ended queue"，它在C++中以模板类的形式存在，允许存储任意类型的数据。

<deque> 是一个动态数组，它提供了快速的随机访问能力，同时允许在两端进行高效的插入和删除操作。

deque()	默认构造函数，创建一个空的 deque 容器。
deque(size_type n)	创建一个包含 n 个默认值元素的 deque 容器。
deque(size_type n, const T& value)	创建一个包含 n 个值为 value 的 deque 容器。
deque(initializer_list<T> il)	使用初始化列表 il 构造 deque 容器。
operator=	赋值操作符，赋值给 deque 容器。
assign(it.begin(),it.end())	用 新容器的值 替换 deque 容器中的所有元素。
at(size_type pos)	返回 pos 位置的元素，并进行范围检查。
operator[](size_type pos)	返回 pos 位置的元素，不进行范围检查。
front()	返回第一个元素的引用。
back()	返回最后一个元素的引用。
begin()	返回指向第一个元素的迭代器。
end()	返回指向末尾元素后一位置的迭代器。
rbegin()	返回指向最后一个元素的逆向迭代器。
rend()	返回指向第一个元素之前位置的逆向迭代器。
empty()	检查容器是否为空。
size()	返回容器中的元素个数。
max_size()	返回容器可容纳的最大元素个数。
clear()	清除容器中的所有元素。
insert(iterator pos, const T& value)	在 pos 位置插入 value 元素。
erase(iterator pos)	移除 pos 位置的元素。
push_back(const T& value)	在容器末尾添加 value 元素。
pop_back()	移除容器末尾的元素。
push_front(const T& value)	在容器前端添加 value 元素。
pop_front()	移除容器前端的元素。
resize(size_type count)	调整容器大小为 count，多出部分用默认值填充。
swap(deque& other)	交换两个 deque 容器的内容。
get_allocator()	返回一个用于构造双端队列的分配器对象的副本。

*/
#include<iostream>
#include<deque>
using namespace std;
//可用operator[]访问dq元素
void print(deque<int> &dq){
    for(int i=0;i<dq.size();i++)cout<<dq[i]<<" ";
    cout<<"\n";
}
//逆向遍历
void antiPrint(deque<int> &dq){
    deque<int>::reverse_iterator it=dq.rbegin();
    for(it;it!=dq.rend();it++)cout<<*it<<" ";
    cout<<"\n";
}
int main(){
    deque<int> dq;
    //头插入
    dq.push_front(0);
    //尾插入
    dq.push_back(1);
    print(dq);

    cout<<"逆序：";
    antiPrint(dq);

    cout<<"容器最大容纳："<<dq.max_size()<<"\n";

    //删除头pop_front
    dq.pop_front();
    print(dq);
    //删除尾pop_back()
    dq.pop_back();
    print(dq);



    return 0;
}