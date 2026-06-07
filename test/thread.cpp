#include<iostream>
#include<thread>
using namespace std;
void count_thread(){
    for(int i=1;i<10;i++){
        for(int j=1;j<=i;j++){
            cout<<i<<"*"<<j<<"="<<i*j<<"\t";
        }
    }
}
void output_thread(){
    char a=97;
    for(int i=0;i<26;i++){
        cout<<a<<endl;
        a+=1;
    }
}
int main(){
    thread count_handle(count_thread);
    
    thread output_handle(output_thread);
    count_handle.detach();   
    return 0;
}