#include<iostream>
using namespace std;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main() {
	int x = 343720, y = 233333, dx = 15, dy = 17, p = y * dx, q = x * dy, g = gcd(p,q);
	p /= g, q /= g;
	int t = 2 * p * x/ dx;
	double ans = t * sqrt(15*15+17*17);
	printf("%.2f",ans);
	return 0;
}
