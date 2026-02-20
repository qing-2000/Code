#include<bits/stdc++.h>
using namespace std;
int main() {
	int x = 233, y = 666;
	double r = sqrt(x * x + y * y),bi=y/x;
	//round()四舍五入
	//l=atan2(666,233)*r   弧长
	cout <<  r*(1+atan2(666,233));
	return 0;
}