#include <iostream>
#include <cstring>
#include<string>
using namespace std;
 
int main ()
{
   char str1[13] = "runoob";
   char str2[13] = "google";
   char str3[13];
   char str4[20]="askjdlagoogle";
   int  len ;
 
   // 复制 str1 到 str3
   strcpy( str3, str1);
   cout << "strcpy( str3, str1) : " << str3 << endl;
 
   // 连接 str1 和 str2
   
   strcat( str1, str2);
   cout << "strcat( str1, str2): " << str1 << endl;
 
   // 连接后，str1 的总长度
   len = strlen(str1);
   cout << "strlen(str1) : " << len << endl;
    
   //strcmp(s1, s2);如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回值小于 0；如果 s1>s2 则返回值大于 0。
   cout<<"strcmp(s1,s2):"<<strcmp(str3,str2)<<endl;

   //返回char*类型指针变量
   const char* pos_ptr = strstr(str4, str2);

    // 检查是否找到，避免对空指针进行计算
    if (pos_ptr != nullptr) {
        // 计算索引：找到的指针 - 字符串开始的指针 = 偏移量（即索引）
        int position = pos_ptr - str4;
        std::cout << "The substring '" << str2 << "' is found at index: " << position << std::endl;
        std::cout << "The memory address is: " << (void*)pos_ptr << std::endl; // 强制转换为 void* 以打印地址
    } else {
        std::cout << "Substring not found." << std::endl;
    }
   return 0;
}