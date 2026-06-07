#include<iostream>
using namespace std;
int main(){
    int a=36168;
    while(a){
        cout<<a%15<<endl;
        a/=15;
    }
    return 0;
}