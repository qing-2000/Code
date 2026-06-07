#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> a){
    for(auto n:a)cout<<n<<" ";
    cout<<"\n";
}

void select_sort(vector<int>& a){
    int len=a.size();
    for(int i=0;i<len;i++){
        int mi=i;
        for(int j=i+1;j<=len-1;j++){
            if(a[j]<a[mi]){
                mi=j;                                   //未排序中最小值的索引
            }
        }
        int temp=a[mi];
        a[mi]=a[i];
        a[i]=temp;                //更新已排序的最小值

    }
}
int main(){ 
    vector<int> a={24567,354678,98765432,1,-9,9090,4};
    select_sort(a);
    print(a);
    return 0;
}