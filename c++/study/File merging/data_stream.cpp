#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int main()
{
    ifstream file("afile.txt");
    if (!file)
    {
        cerr << strerror(errno) << endl;
    }
    file.seekg(1, ios::beg); // 从文件开头偏移 100 字节
    char buffer[4];
    file.read(buffer, sizeof(buffer));
    cout << "从偏移 1 处读取 4 字节:" <<buffer <<endl;

    file.close();
    return 0;
}