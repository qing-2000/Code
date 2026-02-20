#include<iostream>
using namespace std;
int main() {
	int ans=0;
	for (int i = 1; i <= 50; i++) {
		for (int j = i+1; j <= 50; j++) {
			if (!(1 <= i && i <= 7 && 1 < j && j <= 7))
				ans++;
		}
		
	}
	cout << "总的握手次数：" << ans << endl;
	return 0;
}