/*
<iomanip> 是 C++ 标准库中的一个头文件，它提供了对输入/输出流的格式化操作。

iomanip 库中的函数允许开发者控制输出格式，如设置小数点后的位数、设置宽度、对齐方式等。

iomanip 是 Input/Output Manipulators 的缩写，它提供了一组操作符，用于控制 C++ 标准库中的输入/输出流的格式，适用以下场景：

科学计算中浮点数格式的处理；
数据对齐与美化；
显示特定进制或格式的数值。
*/
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    //setw设置宽度
    cout<<"setw设置宽度"<<setw(10)<<10<<"\n";

    //setfill设置填充字符,要和setw一起使用
    cout<<"setfill设置填充字符:"<<setfill('#')<<"\n";
    //混合
    cout<<setfill('*')<<setw(10)<<404<<"\n";

    //设置浮点数有效数位Set precision(x)
    double pi = 3.141592653589793;
    std::cout << "Default: " << pi << "\n";
    std::cout << "Set precision (3): " << std::setprecision(3) << pi << "\n";
    std::cout << "Set precision (7): " << std::setprecision(7) << pi << "\n";
    
    //默认浮点输出格式：根据数值大小自动选择 小数格式 或 科学记数法（例如 1.23e+03）。
    //std::fixed：定点格式（fixed-point notation），强制浮点数始终以 普通小数形式 输出，绝不使用科学记数法。
    cout<<"fixed设置浮点数小数格式："<<fixed<<pi<<"\n";

    //科学计数法
    cout<<"scientific设置浮点数科学计数法格式："<<scientific<<pi<<"\n";

    //oct整数以8进制显示
    cout<<"oct设置8进制："<<oct<<8<<"\n";

    //dec整数以10进制显示
    cout<<"dec设置10进制"<<dec<<'F'<<"\n";

    //hex整数已16进制显示hex
    cout<<"hex设置16进制："<<hex<<16<<"\n";
    
    //showbase显示前缀
    cout<<"showbase显示前缀："<<showbase<<hex<<15<<"\n";

    //uppercase 16进制字母大写
    cout<<uppercase<<"16进制字母大写:"<<0x16<<"\n";

    //nouppercase 16进制字母小写
    cout<<"nouppercase 16进制字母小写："<<nouppercase<<0x16<<"\n";

    //setbase 设置整数的进制
    cout<<"setbase 设置整数的进制(8,10,16)："<<setbase(8)<<10<<"\n";

    //showpos 正数前面显示+
    cout<<"showpos 正数前面显示'+':"<<showpos<<10.908<<"\n";

    int num = 255;

    // 1. 默认输出
    std::cout << "默认: " << num << '\n';

    // 2. 使用 setiosflags 开启 showbase 和 hex 标志
    std::cout << std::setiosflags(std::ios::showbase | std::ios::hex)<< "设置后: " << num << '\n';

    // 3. 再输出一个数，注意标志仍然有效（持续生效）
    std::cout << "还是 hex: " << 16 << '\n';

    // 4. 使用 resetiosflags 仅关闭 hex 标志，showbase 仍然开启
    std::cout << std::resetiosflags(std::ios::hex)<< "关闭 hex 后: " << num << '\n';

    // 5. 完全重置所有标志（或单独关闭 showbase）
    std::cout << std::resetiosflags(std::ios::showbase)<< "完全恢复: " << num << '\n';
    
    return 0;
}
