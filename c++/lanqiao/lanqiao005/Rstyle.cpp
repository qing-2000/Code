#include<iostream>//c++，cin，cout
#include<cmath>//引用pow(n,m)函数，求n的m次方（为浮点型）
using namespace std;

int main() {
	int n,R,t,ans;
	float f,d;
	cout << "输入整形：";
	cin >> n;
	cout << "输入浮点形：";
	cin >> f;
	d = f * pow(2, n);//浮点数*2的n次方原数
	t = 10 * d;
	int temp = int(t) % 10;//小数点第一位的值
	if (temp > 4)
		ans = int(d) + 1;
	else
		ans = int(d);
	cout << "转化后的R格式为："<< ans << endl;
	return 0;
}