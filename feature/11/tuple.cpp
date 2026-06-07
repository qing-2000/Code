#include<tuple>
#include<iostream>
#include<cstring>
using namespace std;
//使用<>核心原因：元组的索引必须在编译期确定
auto get_student(int id)
{
    // 返回类型被推断为 std::tuple<double, char, std::string>
    if (id == 0)
        return std::make_tuple(3.8, 'A', "张三");
    if (id == 1)
        return std::make_tuple(2.9, 'C', "李四");
    if (id == 2)
        return std::make_tuple(1.7, 'D', "王五");
    return std::make_tuple(0.0, 'D', "null");   
    // 如果只写 0 会出现推断错误, 编译失败
}
int main(){
    std::tuple<double, char, std::string> t{3.8, 'A', "张三"};
    double gpa;
    char leval;
    string name;
    tie(gpa,leval,name)=t;//将t内容进行赋值

    auto student = get_student(0);
    gpa=get<0>(student);            //3.8
    leval=get<1>(student);          //A
    name=get<2>(student);           //张三

    std::tie(gpa, leval , name) = get_student(1); //2.9,c,李四
    
    return 0;
}