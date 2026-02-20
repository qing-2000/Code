#include<bits/stdc++.h>
using namespace std;
bool check(int num) {
	for (int i = -num; i <= num ; i++) {
		for (int j = 3; j <= 2 * num + 1; j++) {
			int sum = (i + i + j - 1) * j / 2;//项数和
			if (sum == num)return true;
		}
	}
	return false;
}

int main() {
	int ans = 0;
	int n;
	cin >> n;
	for (int i = 1; i <=n; i++) {
		/*if (!check(i)) {//规律除了0和1均可
			ans++;
			cout << i << " ";
		}*/
		ans += i != 1;
	}cout << endl;
	//cout << ans;
	return 0;
}