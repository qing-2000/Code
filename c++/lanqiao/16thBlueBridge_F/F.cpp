#include<bits/stdc++.h>
using namespace std;
bool checkfunction(string a, string b, int lastpos) {
	for (int i = lastpos - 1; i >= 0; i--) {
		if (a[i] != '.' && b[i] != '.') {
			if ((a[i] != a[lastpos]) || b[i] != b[lastpos]) {//倒叙,第一个非。。与尾异位时
				return true;
			}
		}
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	cin.ignore();
	string a, b;
	cin >> a;
	cin >> b;
	//#....
	//....#

	//......
	//#....#

	//.....#
	//#.....

	//#....#
	//......
	//.##.....#
	//.#.#.#...
	int start,ans=0,end;
	for (int i = 0; i < n; i++) {
		if (a[i] == '#' && b[i] == '.' || a[i] == '.' && b[i] == '#' || a[i] == '#' && b[i] == '#') {
			start = i;
			break;
		}
	}//非。。起点索引
	for (int i = n-1; i >= 0; i--) {
		if (a[i] == '#' && b[i] == '.' || a[i] == '.' && b[i] == '#' || a[i] == '#' && b[i] == '#') {
			end = i;
			break;
		}
	}//非。。终点索引
	if (start == n - 1) {
		cout << 0;
		exit(0);
	}//若起点==最后，无论哪种状态均视为联通，无需添加装置
	int temp = start;//遍历前驱
	for (int i = start+1; i <= end ; i++) {
		
		if (i == end) {//尾判断	
			if (checkfunction(a,b,i))ans++;
			break;
		}
		if (a[i] == '.' && b[i] == '.') {
			ans++;
			continue;
		}
		if (a[i] == '#' && b[i] == '.') {
			if (a[temp] == '.' && b[temp] == '#')ans++;
		}
		else if (a[i] == '.' && b[i] == '#') {
			if (a[temp] == '#' && b[temp] == '.')ans++;
		}
		temp++;
	}
	cout << ans;
	return 0;
}