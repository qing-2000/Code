//递归实现全排列
#include<iostream>
using namespace std;
#define Swap(a,b) do {\
    __typeof__(a) temp;\
    temp=(a);\
    (a)=(b);\
    (b)=temp;\
}while(0)
int arr[3]={0,0,0};
int ans=0;
void func(int begin,int end){
   if(begin==end){
        ans+=1;
   }
   else{
    for(int i=begin;i<=end;i++){
        Swap(arr[begin],arr[i]);
        func(begin+1,end);
        Swap(arr[begin],arr[i]);
    }
   }
}
int main(){
    func(0,2);//begin=arr[0],end=sizeof(arr)/sizeof(arr[0])
    cout<<"arr[]的全排列有："<<ans<<"种。"<<endl;
    return 0;
}