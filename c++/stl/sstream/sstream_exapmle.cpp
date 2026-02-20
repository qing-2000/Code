#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
//仅适用于纯数字，如22 33 44 55
int main(){
    string str;
    getline(cin,str);
    istringstream iss(str);
    vector<int> a;
    int tmp;
    while(iss>>tmp){
        a.push_back(tmp);
    }

    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    
    return 0;
}