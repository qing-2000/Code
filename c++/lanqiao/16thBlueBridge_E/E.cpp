#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int b[N];
void main() {
	int n,m;
	cin >> n>>m;
	for (int i = 1; i <= n; i++)cin >> b[i];
	sort(b + 1, b + n + 1);
	int ans = LLONG_MAX;
	for (int i = m; i <=n; i++)ans = min(ans, b[i] * b[i] - b[i - m + 1] * b[i - m + 1]);
	cout << ans;
	//return 0;
}