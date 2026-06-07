//使用函数指针
#include<iostream>
#include<thread>
using namespace std;
void f(int num){
    for(int i=0;i<num;i++){
        cout<<"hello from thread:"<<i<<endl;
    }
}
int main(){
    thread t1(f,5);
    t1.join();
    return 0;
}