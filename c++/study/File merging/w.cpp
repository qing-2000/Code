#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main(){
    ofstream outfile("bfile.txt");//写入文件默认覆盖
    if(!outfile){
        cerr<<"无法创建文件"<<endl;
    }
    outfile<<"Hello World!"<<endl;
    outfile.close();
    return 0;
}
