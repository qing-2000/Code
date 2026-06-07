/*
<vector> 是一个序列容器，它允许用户在容器的末尾快速地添加或删除元素。
与数组相比，<vector> 提供了更多的功能，如自动调整大小、随机访问等。
*/

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &arr){
    for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";
    cout<<"\n";
}

int main(){
    //创建vector<type> vectorName(size,default_value);
    vector<int> vec1(5,0);
    print(vec1);

    //.push_back() .emplace_back()末尾添加元素
    vec1.push_back(1);
    vec1.emplace_back(2);
    print(vec1);

    //.size()获取容器大小
    cout<<"增加两个元素后的大小为："<<vec1.size()<<"\n";

    //.pop_back()删除末尾元素
    vec1.pop_back();
    print(vec1);

    //.at()访问指定元素
    cout<<vec1.at(5)<<"\n";

    //.front()访问第一个
    //.back()访问最后一个
    cout<<"第一个元素："<<vec1.front()<<" "<<"最后一个元素："<<vec1.back()<<"\n";

    //reserve(n)预留至少n个元素的空间
    vec1.reserve(10);

    //.resize()重置容器大小
    vec1.resize(20);

        //.capacity()查看当前分配的容量
    cout<<"当前分配的容量为："<<vec1.capacity()<<"\n";

    //.insert(iterator,num,val)在iterator添加num个元素val
    //.insert(iterator,vector2.begin(),vector2.end())在当前容器中插入容器2的值，范围[begin(),end())
    vector<int>::iterator it=vec1.begin();
    vec1.insert(it,100);
    print(vec1);

    //.erase(iterator.begin(),iterator.end())删除元素
    vec1.erase(it);//删除一个
    print(vec1);
    vec1.erase(it+2,it+5);//范围删除[)
    print(vec1);

    //.clear()清空容器
    vec1.clear();

    //.empty()判断容器是否为空
    cout<<"容器空为1，非空为0："<<vec1.empty()<<"\n";

    return 0;
}
