#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int i=0x12345678;
    unsigned char* p=(unsigned char*)&i;
    if (*p == 0x78) {
        printf("小端\n");
    } else if (*p == 0x12) {
        printf("大端\n");
    }
    return 0;
}