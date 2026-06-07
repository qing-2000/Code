#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string s1="100 20.5 101 21.5";
    int intiger;
    double dou;
    stringstream sst(s1);
    sst>>intiger>>dou;
    cout<<intiger<<dou<<endl;
    //混合vector使用
    vector<int> ints;
    vector<double> doubles;
    int i;
    double d;
    while(sst>>i>>d){
        ints.emplace_back(i);
        doubles.emplace_back(d);
    }
    sst.str(""); // 清空stringstream
    for(int i=0;i<ints.size();i++){
        cout<<ints[i]<<" "<<doubles[i]<<"\n";
    }
    /*
    10020.5
    101 21.5
    原因：对于intiger,dou只赋值一次后停留在20.5后的空格，此时再读取
    */
    return 0;
}