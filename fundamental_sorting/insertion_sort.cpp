#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> a){
    for(auto n:a)cout<<n<<" ";
    cout<<"\n";
}
void insertSort(vector<int>& a){
    int len=a.size();
    for(int i=1;i<len;i++){
        int j=i-1;
        int ma=a[i];                    //选取未排序中的作为假定最大值
        while(j>=0&&a[j]>ma){               //从已排序数组后往前扫描，大的往后挪
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=ma;                  //插入位置
    }

}
int main(){
    vector<int> a={983746,-12345,90,999999999,654321,-55};
    insertSort(a);
    print(a);

    return 0;
}