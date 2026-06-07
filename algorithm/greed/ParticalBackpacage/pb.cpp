//部分背包问题：每件物品是可再分的，即允许将某件物品的一部分（例如 1/3）放入背包；
//直接求单位最值比例
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<iomanip>
using namespace std;
// template<typename T>
// T max(T a,T b){
//     if(a>b) return a;
//     return b;
// }
struct kv{
    double key;
    int pos;
};
double maxBenefit(std::vector<int> v,std::vector<int> w,int total){
    double ans=0;
    //unordered_map<double,int> um(v.size());
    vector<kv> temp(v.size());
    for(int i=0;i<v.size();i++){
        temp[i].key=(double)v[i]/w[i];
        temp[i].pos=i;
    }
    sort(temp.begin(),temp.end(),[](const kv& a, const kv& b) {
        return a.key > b.key;
    });
    int remain = total;
    for (int i = 0; i < v.size(); ++i) {
        int idx = temp[i].pos;
        if (remain >= w[idx]) {
            ans += v[idx];
            remain -= w[idx];
        } else {
            ans += (double)remain / w[idx] * v[idx];
            break;
        }
    }
    return ans;
}

int main(){
    vector<int> value={60,120,100};
    vector<int> weight={10,20,30};
    int Capacity=50;
    double ans=maxBenefit(value,weight,Capacity);
    cout<<fixed<<setprecision(5)<<ans;
    return 0;
}