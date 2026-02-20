#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int a, b, c, k;
		cin >> a >> b >> c >> k;
		for (int i = 0; i < k; i++) {
			int ta = (b + c) / 2;
			int tb = (a + c) / 2;
			int tc = (a + b) / 2;
			a = ta, b = tb, c = tc;
			if (a == b && b == c)break;
		}
		cout << a <<" " << b << " " << c << endl;
	}
	return 0;
}