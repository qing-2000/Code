#include <iostream>
#include<stdio.h>
using namespace std;
int main()
{
	// 请在此输入您的代码
	int n;
	cin >> n;
	char ch = 'A';
	if(n>0)
	  ch = 'A' + (n-1);
	printf("%c", ch);
	return 0;
}