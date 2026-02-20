#include <iostream>
#include <stack>
int main()
{
    std::stack<char> s;
    // reverse 字符串
    char c[1024];
    std::cout << "请输入字符串：";
    
    //字符数组末尾是\0，且算入索引长度

    std::cin.getline(c, 21);
    for (int i = 0; i <= 20; i++)
    {
        if (c[i] == ' '||c[i]=='\0')
        {
            while (!s.empty())
            {
                char temp = s.top();
                std::cout << temp;
                s.pop();
            }
            std::cout<<" ";
        }
        else
            s.push(c[i]);
    }
    std::cout<<"当前栈内有:"<<s.size()<<"个元素"<<std::endl;
    return 0;
}