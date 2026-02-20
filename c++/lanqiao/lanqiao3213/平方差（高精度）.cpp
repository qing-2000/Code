#include <iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    // 请在此输入您的代码
    
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    if (s1[0] == '-')s1[0] = '0';
    if (s2[0] == '-')s2[0] = '0';
    /*
    for (int i = s1.size() - 1; i > -1; i--) {
        cout << s1[i];
    }
    cout << endl;
    for (int i = s2.size() - 1; i > -1; i--) {
        cout << s2[i];
    }
    */
    int a[200] = { 0 }, b[200] = { 0 }, c[400] = { 0 }, al, bl, d[200] = { 0 },n,m;
    for (int i = 0; i <200; i++) {
        //加法
        n = s1.size() - 1;
        m = s2.size() - 1;
        al = n- i; //有效低位索引
        bl = m- i;
      
        if (al < 0 && bl < 0)break;
    
        if (al >= 0 && bl >= 0) {
            a[i] = (s1[al]- '0') + (s2[bl] - '0');
            cout << a[i] << endl;
        }
        else if (al >= 0 ) {//a>b:a-b
            a[i] = s1[al] - '0';
            cout << a[i] << endl;

            
        }else if (bl >= 0) {
            a[i] = s2[bl] - '0';
            cout << a[i] << endl;
        }
        //减
        if (al >= 0 && bl >= 0) {
            if (al>=bl) {
                b[i] = (s1[al] - '0') - (s2[bl] - '0');
                cout << b[i] << endl;
            }
            else {
                b[i] = (s2[bl] - '0') - (s1[al] - '0');
                cout << b[i] << endl;
            }
            
        }
        else if ( al>= 0 ) {//a>b:a-b
            b[i] = s1[al] - '0';
            cout << b[i] << endl;
        }
        else if ( bl>= 0 ) {
            b[i] = s2[bl] - '0';
            cout << b[i] << endl;
        }
        
        
    }
    for (int i = 0; i < 200; i++) {
        if (a[i] > 9) {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
        while (b[i] < 0) {
            b[i + 1] -= 1;
            b[i] += 10;
        }
        
    }
    int am=199;
    while (am && a[am] == 0) {
        am -= 1;
    }
    for (int i = am; i >-1;i-- ) {
        cout << a[i] << " ";
    }
    cout << endl;
    int bm = 199;
    while (bm && b[bm] == 0) {
        bm -= 1;
    }
    cout << endl;
    for (int i = bm; i > -1; i--) {
        cout << b[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 200; i++) {
        
        for (int j = 0; j < 200 ; j++) {
            c[i+j] += a[i] * b[j];
        }
    }
    for (int i = 0; i < 400; i++) {
        if (c[i] > 9) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
    int count=399;
    for (int i = 399; i > -1; i--) {
        if (c[i] > 0) {
            count = i;
            break;
        }
    }
    for (int i = count; i > -1; i--) {
        cout << c[i];
    }
    return 0;
}