/*
<stack> 是 C++ 标准模板库（STL）的一部分，它实现了一个后进先出（LIFO，Last In First Out）的数据结构。
这种数据结构非常适合于需要"最后添加的元素最先被移除"的场景。

<stack> 容器适配器提供了一个栈的接口，它基于其他容器（如 deque 或 vector）来实现。
栈的元素是线性排列的，但只允许在一端（栈顶）进行添加和移除操作。

push(): 在栈顶添加一个元素。
pop(): 移除栈顶元素。
top(): 返回栈顶元素的引用，但不移除它。
empty(): 检查栈是否为空。
size(): 返回栈中元素的数量。
*/
#include<iostream>
#include<stack>
using namespace std;
//只能通过top和删除栈顶访问各元素
void print(stack<int> &s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
}
int main(){
    stack<int> s;
    // 向栈中添加元素
    s.push(1);
    s.push(2);
    s.push(3);

    // 访问栈顶元素
    std::cout << "Top element is: " << s.top() << std::endl;

    // 移除栈顶元素
    s.pop();
    std::cout << "After popping, top element is: " << s.top() << std::endl;

    // 检查栈是否为空
    if (!s.empty()) {
        std::cout << "Stack is not empty." << std::endl;
    }

    // 打印栈的大小
    std::cout << "Size of stack: " << s.size() << std::endl;

    print(s);
    return 0;
}