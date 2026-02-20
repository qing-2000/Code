#include<iostream>
using namespace std;
int main() {
	int arr[10] = {-2,1,-3,4,-1,2,1,-5,4};
	int current_num=arr[0], max_num=arr[0];
	for (int i = 1; i < 10;i++) {
		if ((current_num + arr[i]) > current_num)current_num = current_num+arr[i];
		else current_num = arr[i];
		max_num = max(max_num, current_num);
	}
	cout << "最大子数组和：" << max_num<<endl;
	cout << "当前大小：" << current_num;
	return -1;
}