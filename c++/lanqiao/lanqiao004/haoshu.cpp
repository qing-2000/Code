#include<iostream>
using namespace std;
bool check(int n) {
	int cnt = 1;//记录数位
	while (n) {
		int b = n % 10;//取余，第一次为奇数位上的值，第二次为偶数位上的值...
		if (cnt % 2 == 1) {//判断数位的奇偶性
			if (b % 2 != 1) //判断奇数位上的值是否为奇数
				return false;
		}
		else {
		    if (b % 2 != 0)//判断偶数位上的值是否为偶数
			    return false;
		}
		cnt++;//自加，确保数位匹配
		n /= 10;
	}
	return true;
}
int main() {
	int n=0,ans=0;
	cin >> n;//从键盘输入要找好数个数的范围
	for (int i = 1; i <= n; i++) {
		if (i % 10 % 2 == 0) continue;//若奇数位0-10为偶数，则跳过避免浪费
		if(check(i))//判断i是否为好数
			ans++;
	}
	cout << ans << endl;
	return 0;
}