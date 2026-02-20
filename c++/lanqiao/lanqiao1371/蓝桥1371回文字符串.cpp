#include <bits/stdc++.h>
#include<string>
using namespace std;


int main()
{
	// 请在此输入您的代码
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	
	getline(cin,s);
	
	bool i = true;
	int k = s.length()/2;
	for (int j = 0;j<k;j++) {
		if (*(s.begin() + j) != *(s.end() - 1-j)) {
			i = false;
			break;
		}
	}
	if (i)cout << 'Y'; 
	else cout << 'N';
	return 0;
}