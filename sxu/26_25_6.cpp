#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    stack<int> arr;
    while(n){
        arr.push(n%2);
        n/=2;
    }
    while(!arr.empty()){
        cout<<arr.top();
        arr.pop();
    }
    return 0;   
}