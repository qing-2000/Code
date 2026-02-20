//floor()向下取整
#include<bits/stdc++.h>
using namespace std;
int main() {
	int ans = 1,mod=1e9+7;
	for (int i = 1; i < 1013; i++) {
		ans *= 2;
		ans %= mod;
	}
	cout << ans;
	return 0;
}