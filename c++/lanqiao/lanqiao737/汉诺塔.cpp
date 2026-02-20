#include <iostream>
using namespace std;
unsigned long long han(unsigned long long i) {
	if (i == 1 )return 1;
	return han(i - 1) * 2 + 1;
}
int main()
{
	// 请在此输入您的代码
	cout<<han(64);

	return 0;
}