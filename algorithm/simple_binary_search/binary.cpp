#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//返回数组中第一个等于指定值的位置
// >=指定致，缩小右区间，否则扩大左区间（+1）
// 返回左
//等价于lower_bound
int function1(vector<int>& a, int num) {
	auto l = a.begin(),r=a.end();
	while (l < r) {
		auto mid = l + (r - l) / 2;
		if (*mid >= num) {
			r = mid;
		}
		else l = mid+1;
	}
	if (*l == num)return l - a.begin();
	else return -1;
}
//返回数组中最后一个等于指定值的位置
// <=指定值，扩大左区间（+1），缩小右区间
// 返回（左-1）
//等价于upper_bound
int function2(vector<int>& a, int num) {
	auto l = a.begin(), r = a.end();
	while (l < r) {
		auto mid = l + (r - l)/2;
		if (*mid <= num) {
			l = mid+1;
		}
		else r = mid;
	}
	if (*(l-1) == num)return (l - 1) - a.begin();
	else return -1;
}
int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cout << "输入要在数组中查找的数：";
	int num,positionfirst,positionend;
	cin >> num;
	if (binary_search(a.begin(), a.end(), num)) {//如果在数组中
		positionfirst = function1(a, num);
		positionend = function2(a, num);
		cout << "该数在有序数组中第一次出现的位置：" << positionfirst<<endl;
		cout << "该数在有序数组中最后一次出现的位置：" << positionend;
	}
	else cout << " 该数不在数组中。";
	return 0;
}