#include<iostream>
#include<vector>
#include"print.h"
#include"my_complex.h"
int main(){
    vector<int> a={1,2,3};
    MyComplex A(2,1);
    
    MyComplex C=MyComplex (3,3);
    
    cout<<A<<" "<<C<<"\n";
    A+=C;
    cout<<A.real()<<" "<<A.imag()<<"\n";
    print(a);
    return 0;
}