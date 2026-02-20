/*
#include<iostream>
using namespace std;
typedef unsigned long long ull;
ull asdf(ull a) {
	ull ans = 0, i = 1;
	while (i <= a) {
		ull temp = a;
		if (temp % i == 0) {
			ans++;
		}
		i++;
	}
	return ans;
}
ull nm(ull a) {
	if (a == 1)return 1;
	else return a * nm(a - 1);
}
int main() {
	ull a = 100;
	cout << nm(a)<<endl;
	cout << asdf(nm(a));
	return 0;
}
*/
#include<iostream>
using namespace std;
int main() {
	int a[120] = { 0 };
	for (int i = 2; i <= 100; i++) {
		int temp = i;
		for (int j = 2; j <= temp;j++) {
			while (temp%j==0) {
				a[j]++;
				temp /= j;
			}
		}
	}
	
	int ans = 1;
	for (int n : a) {
		if (n > 0) {
			
			ans *= (n + 1);
		}
	}
	cout << ans;
	return 0;
}