// inline 内联函数，简单的，更快，只是建议编译器设为inline，具体是不是inline看编译器决定

#include <iostream>
#include <vector>
#include "../head/print.h" //引入外部头文件
using namespace std;

class HJ;

HJ& __doapl(HJ* ths,const HJ& r);


class HJ
{
public:
    // 构造函数创建对象，无返回值,可重载
    //参数传递最好传引用，速度快，加const只读；小于4字节可传值更快
    HJ(double r = 0, double i = 0) // r,i默认参数
        : re(r), im(i)                  // 初始列
    {}

    HJ &operator+=(const HJ &);
   
    //同一个objects互为友元
    int func(const HJ& param)
    {return param.re+param.im;}

    double real() const { return re; } //这里的const不改变里面的数据内容
    double imag() const { return im; }

private:
    double re, im;
    //友元函数声明
    friend HJ& __doapl(HJ *, const HJ &);
};

//友元函数取数据
//返回HJ的引用
inline HJ&
__doapl(HJ* ths,const HJ& r){
    //自由获取private数据
    ths->re+=r.re;
    ths->im +=r.im;
    return *ths;
}

inline HJ&
//在HJ类中对操作符+=进行重载，已满足类的方法运算
HJ::operator+=(const HJ& r) //::作用域解析运算符，实现类中声明的函数
{
    return __doapl(this,r);//this作为形参已隐藏，不能写出来
}

inline HJ
operator + (const HJ& x,const HJ& y){
    return HJ(x.real()+y.real(),x.imag()+y.imag());
}

int main()
{
    const HJ c1(2,1);
    HJ c2(4.4,1.2);
    HJ c3=c2 + c1;
    cout<<"c3: "<<c3.real()<<" "<<c3.imag()<<"\n";
    c2+=c1;
    c2.func(c1);
    cout<<"c2: "<<c2.real()<<" "<<c2.imag()<<"\n";
    return 0;
}