#ifndef __MY_COMPLEX__
#define __MY_COMPLEX__

class MyComplex{
public:
    //构造函数
    MyComplex(double r=0,double i=0)
        :re(r),im(i)
    {}
    
    //重载运算符
    MyComplex& operator +=(const MyComplex&);

    //获取值的方法
    double real() const {return re;}
    double imag() const {return im;}

private:

    double re,im;

    //友元函数直接取private数据
    friend MyComplex&
    __doapl(MyComplex*,const MyComplex&);
};

inline MyComplex&
__doapl(MyComplex* ths,const MyComplex& r)
{
    ths->re+=r.re;
    ths->im+=r.im;

    return *ths;
}

inline MyComplex&
MyComplex::operator +=(const MyComplex& r)
{
    return __doapl(this,r);
}

inline ostream&        //返回值为ostream方便多次输出
operator<<(ostream& os,const MyComplex& c){
    os<<'('<<c.real()<<','<<c.imag()<<')';
    return os;
}

#endif