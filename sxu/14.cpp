#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> func(string s1,string s2){
    //s1<s2交换s1，s2
    if(s1.length()<s2.length()) return func(s2,s1);

    int maxlen=s1.length()>s2.length()?s1.length():s2.length();
    vector<int> arr(maxlen,0);

    int len1=s1.length()-1,temp1=len1; 
    int len2=s2.length()-1,temp2=len2;

    //处理位数不齐
    int count=1;
    for(int i=maxlen-1;i>-1;--i){
        if(count<=len2+1){
            arr[i]+=(s1[temp1]-'0')-(s2[temp2]-'0');
            temp1--;
            temp2--;
        }
        else {
            //计算剩余长度
                arr[i]=s1[temp1]-'0';
                temp1--;
            }
        count++;
    }
    //处理低位负数
    for(int i=maxlen-1;i>-1;--i){
        while(arr[i]<0){
            arr[i]+=10;
            arr[i-1]-=1;
        }
    }
    return arr;
}
int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    s1.erase(0, s1.find_first_not_of('0'));
    s2.erase(0, s2.find_first_not_of(   '0'));
    if (s1.empty()) s1 = "0";
    if (s2.empty()) s2 = "0";
    if(s1=="0"&&s2=="0") return 0;
    vector<int> arr=func(s1,s2);
    //cout<<arr.size()<<endl;
    bool option=false;
    for(int i=0;i<arr.size();i++){
        //处理高位空缺
        if(arr[i]!=0) option=true;
        if(option) cout<<arr[i];
        //cout<<arr[i];
    }
    return 0;
}