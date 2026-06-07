#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> a){
    for(auto n:a)cout<<n<<" ";
    cout<<"\n";
}
int partition(vector<int>& a,int low,int high){
    int pivot=a[high];                              //最右为基准
    int lepivot=low-1;                          //小于基准区元素的最后一个元素的位置

    for(int j=low;j<high;j++){
        //当前小于基准
        if(a[j]<=pivot){
            lepivot++;
            int temp=a[lepivot];
            a[lepivot]=a[j];
            a[j]=temp;
        }
    }

    //将基准交换到最后位置
    int tmep=a[lepivot+1];
    a[lepivot+1]=a[high];
    a[high]=tmep;

    return lepivot+1;
}
void quickSort(vector<int>&  a,int low,int high){
    if(low<high){
        int pos=partition(a,low,high);
        quickSort(a,low,pos-1);
        quickSort(a,pos+1,high);
    }
}
int main(){
    vector<int> a={9875643,234567890,987654,-2345654,-2345,-34567,-90,999};
    int len=a.size()-1;
    quickSort(a,0,len);
    print(a);
    return 0;
}