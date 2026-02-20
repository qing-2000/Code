#include<sstream>
#include<iostream>
using namespace std;
int main(){
    string data="10 20.5";
    istringstream iss(data);
    int i;
    double d;
    iss>>i>>d;
    cout<<"整形："<<i<<endl;
    cout<<"浮点型："<<d<<endl;
    ostringstream oss;
    int a=100;
    double b=200.5;
    oss<<a<<" "<<b;
    string result =oss.str();
    cout<<"Resulting string : "<<result<<endl;
    string data2="30 40.5";
    stringstream ss(data2);
    
    int i1=100;
    double d1=111.111;
    ss>>i1>>d1;
    cout<<"Read Integer: "<<i1<<" "<<"Double:"<<d1<<endl;
    ss.str("");//清空stringstream
    ss.clear();                    // ⭐ 重要：清除错误状态标志！
    ss<<"New data:"<<50<<" "<<60.7;
    string newData=ss.str();
    cout<<"New data string : "<<newData<<endl;
    return 0;
}