#include<iostream>
#include<cctype>
#include<vector>
using namespace std;
int parent[1000];

void init(int a[],int size) {
	for (int i = 0; i < size; i++) {//size=sizeof(a) / sizeof(a[0]);
		a[i] = i;
	}
}
int findroot(int num) {
	if (parent[num] != num) parent[num] = findroot(parent[num]);
	return parent[num];
}
void unionnum(int a, int b) {
	int n1 = findroot(a), n2 = findroot(b);
	if (n1 != n2)parent[n1] = n2;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int len; cin >> len;

	init(parent, len);
	int a, b;
	
	for (int i = 0; i < 7; i++) {
		cin >> a >> b;
		unionnum(a, b);
	}
	for (int i = 0; i < len; i++) {
		cout << findroot(i) << " ";
	}
	cout << endl;
	// 修正点：使用 vector<vector<int>> 存储集合
	vector<vector<int>> Set(len);  // 每个根节点对应一个集合

	for (int i = 0; i < len; i++) {
		int root = findroot(i);    // 确保路径压缩后的根
		Set[root].push_back(i);    // 将元素 i 加入其根节点的集合
	}
	// 输出所有集合
	for (int i = 0; i < len; i++) {
		if (!Set[i].empty()) {
			cout << "集合 " << i << ": ";
			for (int num : Set[i]) {
				cout << num << " ";
			}
			cout << endl;
		}
	}
	bool floor = true;
	while (floor) {
		cout << "输入要查找父节点的位置:";
		int position; cin >> position;
		cout << findroot(position)<<endl;
		cout << "是否继续查找父节点[Y/N]?";
		char choice;
		cin >> choice;
		if (toupper(choice) == 'N')floor = false;
		system("cls");
	}
	return 0;
}