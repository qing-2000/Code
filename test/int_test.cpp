#include<iostream>
#include<string>
using namespace std;
int main(){
    int a=2112340000;
    int b=2100001234;
    int c=a+b;
    a=c-a;
    b=c-b;
    //不合法但跑成功了,UB处理的结果
    cout<<a<<" "<<b<<endl;

    //int转string
    string s=to_string(a);
    string::iterator it=s.begin();
    while(it!=s.end()){
        cout<<*it<<" ";
        it++;
    }
    return 0;
}