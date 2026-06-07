#include <iostream>
#define PI 3.14 // 预处理，或者说宏
#ifndef NULL    // 如果NULL没有定义则定义为0
#define NULL 0
#endif // 结束
#define STR(x) #x
#define concat(a, b) a##b // ##表示连接，，，，，将concat（a，b）变为ab
int main()
{
    std::cout << "半径为1的园的面积：" << PI << std::endl;

    std::cout << "birthday:" << STR(6.15) << std::endl;
    
    int ab = 666;
    std::cout << "ab的值：" << concat(a, b) << std::endl;
    //行号
    std::cout << "Value of __LINE__ : " << __LINE__ << std::endl;
    //当前文件
    std::cout << "Value of __FILE__ : " << __FILE__ << std::endl;
    //将源文件转换为目标代码的日期。
    std::cout << "Value of __DATE__ : " << __DATE__ << std::endl;
    //程序编译的时间
    std::cout << "Value of __TIME__ : " << __TIME__ << std::endl;
    return 0;
}