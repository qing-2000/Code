#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
class model{
    public :
    //构造函数，调用时执行
        model(){
            std::cout<<"func开始调用。。。"<<std::endl;
            
        }
    //析构函数，摧毁时执行
        ~model(){
            std::cout<<"func开始关闭。。。"<<std::endl;
        }
};
int main(){
    std::string arr;
    std::cout<<"请输入字符串："<<std::endl;
    std::getline(std::cin,arr);
    std::cout<<arr<<std::endl;
    auto size=arr.length();
    char* buffer=new char[size+1];//动态内存分配
    buffer[size]='\0';
    strcpy(buffer,arr.c_str());//不能直接赋值
    std::cout<<"刚才输入的字符串是："<<buffer<<std::endl;
    delete[] buffer;

    model* myModel=new model[4];
    delete[] myModel;
    return 0;
}