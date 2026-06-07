#include<iostream>
#include<thread>
#include<mutex>
#include<cstdlib>
int a=0;
std::mutex mtx;
void func(){
    for(int i=0;i<10;i++){
        std::lock_guard<std::mutex>lg(mtx);
        std::cout<<"func:a已加锁"<<std::endl;
        a+=10;
        std::cout<<"func:a已解锁"<<std::endl;
        std::cout<<"a的值："<<a<<std::endl;
    }
}
void func2(){
    for(int i=0;i<10;i++){
        std::cout<<"func2:a已加锁"<<std::endl;
        std::lock_guard<std::mutex>lg(mtx);
        a+=10;
        std::cout<<"func2:a已解锁"<<std::endl;
        std::cout<<"a的值："<<a<<std::endl;
    }
}
int main(){
    std::thread t1(func);
    std::thread t2(func2);
    t1.detach();
    t2.detach();
    system("pasue");
    return 0;
}