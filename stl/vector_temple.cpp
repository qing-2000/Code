#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm> //包含sort
#include <cctype>    //toupper(),tolower()
#include<typeinfo>//判断类型
std::vector<int> arr;
std::vector<int>::iterator it; // 打印
char cha;
void Print()
{
    it=arr.begin();
    std::cout<<"该容器元素为：";
    for (it; it < arr.end(); it++)
    {
        printf("%d\t", *it);
    }
    std::cout << "该容器长度为：" << arr.size() << std::endl;
}
bool isEmpty = arr.empty(); // 判断是否为空

void isempty()
{
    if (isEmpty)
        printf("该容器不为空！\n");
    else
        std::cout << "该容器为空！" << std::endl;
}

bool isOut(int a)
{
    if (a > arr.size())
        return true;
    else
        return false;
}

bool isInsert()
{
    if (toupper(cha) == 'Y')
        return true;
    else
        return false;
}
bool isDelete()
{
    if (toupper(cha) == 'Y')
        return true;
    else
        return false;
}
void insert(int i, int num)
{
    arr.insert(arr.begin() + (i - 1), num); // 在第3个位置插入2：insert(arr.begin()+2,2)，插入多个数：insert(arr.end(),10,5)在末尾插入10个5
}
void del(int i)
{
    arr.erase(arr.begin() + (i - 1)); // 删除第i个位置的元素
}
bool isOver(){
    if (toupper(cha) == 'Y')
        return true;
    else
        return false;
}
int main()
{

    int total, var;
    std::cout << "输入循环次数：";
    std::cin >> total;
    while (total)
    {
        std::cout << "输入变量：";
        std::cin >> var;

        arr.push_back(var);
        total -= 1;
    }
    it = arr.begin();
    std::sort(arr.begin(), arr.end()); // algorithm函数，排序
    Print();

    reverse(arr.begin(), arr.end()); // 翻转容器
    std::cout<<"翻转后的";
    Print();
    int pos, insert_val;
    while (1)
    {
        std::cout << "是否在容器中插入元素?[Y/N]";
        std::cin >> cha;
        while (isInsert())
        {
            std::cout << "请输入插入位置：";
            std::cin >> pos;
            std::cout << "请输入要插入的元素：";
            std::cin >> insert_val;
            if (!isOut(pos))
            {
                insert(pos, insert_val);
                Print();
            }
            else
                std::cout << "该位置越界！" << std::endl;
            std::cout<<"出入后";
            Print();
            std::cout << "是否在容器中插入元素?[Y/N]";
            std::cin >> cha;
        }

        std::cout << "是否在删除容器中元素?[Y/N]";
        std::cin >> cha;
        while (isDelete())
        {
            std::cout << "请输入要删除的位置：";
            std::cin >> pos;
            del(pos);
            std::cout<<"删除后";
            Print();
            std::cout << "是否在删除容器中元素?[Y/N]";
            std::cin >> cha;
        }
        std::cout<<"是否结束对容器的操作？[Y/N]";
        std::cin>>cha;
        if(isOver())
            break;
        std::cin.ignore();
    }

    return 0;
}