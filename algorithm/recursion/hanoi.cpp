#include<iostream>
using namespace std;
void hanoi(int num,char sou,char tar,char aux){
    static auto count=1;
    if(num==1){//仅1个的情况下，直接移动到目标柱
        cout<<"第"<<count<<"次:从"<<sou<<"移动至"<<tar<<"\n";
        count++;
    }else{
        hanoi(num-1,sou,aux,tar);//将上一个移动到辅助柱，盘子数量-1
        cout<<"第"<<count<<"次:从"<<sou<<"移动至"<<tar<<"\n";
        count++;
        hanoi(num-1,aux,tar,sou);//将辅助上的盘子移动到目标柱
    }
}
int main(){
    hanoi(3,'A','B','C');
    return 0;
}