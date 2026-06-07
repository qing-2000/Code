#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main(){
    ifstream infile("afile.txt");//打开文件
    if(!infile){
        cerr<<strerror(errno)<<endl;
    }
    string content;
    while(getline(infile,content)){//按行读取
        cout<<content<<endl;
    }
    infile.close();
    return 0;
}