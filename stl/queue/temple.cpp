/*
队列是一种先进先出（FIFO, First In First Out）的数据结构，它允许在一端添加元素（称为队尾），并在另一端移除元素（称为队首）。

队列是一种线性数据结构，它遵循以下规则：

元素只能从队尾添加。
元素只能从队首移除。

队列提供了以下常用操作：
empty(): 检查队列是否为空。
size(): 返回队列中的元素数量。
front(): 返回队首元素的引用。
back(): 返回队尾元素的引用。
push(): 在队尾添加一个元素。
pop(): 移除队首元素。
*/
#include<iostream>
#include<queue>
using namespace std;
//遍历及删除
void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<"\n";
}
int main(){
    // 创建一个整数队列
    std::queue<int> q;

    // 向队列中添加元素
    q.push(10);
    q.push(20);
    q.push(30);

    // 打印队列中的元素数量
    std::cout << "队列中的元素数量: " << q.size() << std::endl;

    // 打印队首元素
    std::cout << "队首元素: " << q.front() << std::endl;

    // 打印队尾元素
    std::cout << "队尾元素: " << q.back() << std::endl;

    // 移除队首元素
    q.pop();
    std::cout << "移除队首元素后，队首元素: " << q.front() << std::endl;

    // 再次打印队列中的元素数量
    std::cout << "队列中的元素数量: " << q.size() << std::endl;
    
    print(q);
    
    return 0;
}