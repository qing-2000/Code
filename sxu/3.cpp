#include<iostream>
#include<vector>
using namespace std;
int main() {
    int a, b, c;
    vector<int> res;
    while(cin>>a){
        if(a==0)break;
        cin>>b;
        res.push_back(a+b);
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    return 0;
}
/*
int main() {
    int a, b,c;
    vector<int> res;
    while (cin >> a) {
        if (a == 0) {
            cin.ignore(1);  
            if (cin.peek() == '\n' || cin.peek() == EOF) {
                break;  
            } else {
                cin.unget();
                cin >> a >> b;
                res.push_back(a+b);
            }
        } else {
            cin >> b;
            res.push_back(a+b);
        }
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    return 0;
}*/