#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> a){
    for(auto n:a)cout<<n<<" ";
    cout<<"\n";
}
void shellSort(vector<int>& a){
    size_t len=a.size();

    for(int gap=len/2;gap>0;gap/=2){           //分区间
        
        for(int i=gap;i<len;i++){              //区间内insert sort
            size_t j=i;
            int temp=a[i];
            while(j>=gap&&a[j-gap]>temp){
                a[j]=a[j-gap];
                j-=gap;
            }
            a[j]=temp;
        }

    }
}
int main(){
    vector<int> a={908987656,-909876543,2,999,-876543234,0,1};
    shellSort(a);
    print(a);
    return 0;
}