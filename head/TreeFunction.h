//string 设计
#ifndef __MYSTRING__
#define __MYSTRING__

#include<cstring>

class MyString{
public:
    MyString(const char* cstr = 0);
    //拷贝构造
    MyString(const MyString& str);
    //拷贝赋值
    MyString& operator=(const MyString& str);
    //析构函数，离开作用域释放资源
    ~MyString();
    char* get_c_str() const {return m_data;};
private:
    char* m_data;

};
inline
MyString :: MyString(const char* cstr=0){
    if(cstr){
        //有参数
        m_data=new char[strlen(cstr)+1];
        strcpy(m_data,cstr);
    }else{
        //无参数，指针指向结束符
        m_data=new char[1];
        *m_data='\0';
    }
}

inline
MyString::~MyString(){
    delete[] m_data;
}

inline MyString&
MyString::operator=(const MyString& s){
    return *this=s;
}


#endif