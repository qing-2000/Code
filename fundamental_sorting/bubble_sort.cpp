#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> a){
    for(auto n:a)cout<<n<<" ";
    cout<<"\n";
}
void BubbleSort(vector<int>& a){
    int len=a.size();
    for(int i=0;i<len;i++){
        for(int j=0;j<len-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int  main(){    
    vector<int> arr={9,8,7,6,5,4,3,2,1,0};
    BubbleSort(arr);
    cout<<"冒泡排序后：";
    print(arr);
    return 0;
}