#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };//存储节点
int Size[10] = { 1,1,1,1,1,1,1,1,1,1 };//存储集合大小
//查找根
int find(int position) {
	if(position != arr[position])
        arr[position]=find(arr[position]);
	return arr[position];
}
void join(int x, int y, vector<string>& output) {
    int roota = find(x);
    int rootb = find(y);
    //这是一个检查两个元素（X 和 Y）是否属于同一个集合的判断。
    // 如果它们的根节点不相同，说明它们在不同的集合中，需要进行合并操作。
    if (roota != rootb) {
        // size[rootX] 和 size[rootY] 表示的是根节点 rootX 和 rootY 所在集合的大小（即集合中元素的数量）。
        //按大小合并的思想是：将小的集合（元素少的集合）合并到大的集合（元素多的集合）下，以此保持树的高度较低。
        if (Size[roota] < Size[rootb]) {
            //这是合并的操作。如果 size[rootX] 小于 size[rootY]，
            // 那么将 rootX 的父节点指向 rootY，
            // 即将 X 所在的集合合并到 Y 所在的集合下。
            arr[roota] = rootb;
            //更新合并后的新集合的大小。
            // 因为 rootX 被合并到了 rootY 下，
            // 所以新集合的大小应该是原先两个集合大小之和。
            Size[rootb] += Size[roota];
        }
        else {
            arr[rootb] = roota;
            Size[roota] += Size[rootb];
        }
        output.push_back(to_string(x)+" "+to_string(y));
    }
}
bool check(int num, vector<int>&Set) {
    for (int i = 0; i < Set.size(); i++) {
        if (num == Set[i])return true;
    }
    return false;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int x, y;
    vector<string>output;
    vector<int>Set;
    map<int, vector<int>>sets;
    // 链接两个数
	for (int i = 0; i < 10; i++) {
		cin >> x >> y;
		join(x, y,output);
	}
    cout << endl;
    //输出有效链接的两个数的操作
    cout << "合并操作：" << endl;
    for (auto& n : output)cout << n << endl;
    Set.push_back ( find(0));
    
    for (int i = 0; i < 10; i++) {
        int root = find(i);
        sets[root].push_back(i); // 将节点i加入其根节点对应的集合中
        if (!check(root, Set)) {
            Set.push_back(root);
        }
    }

    //输出集合数量

    cout << "有" << Set.size() << "个集合" << endl;
    for (auto& n : Set)cout << n << endl;
    
   
    //输出集合
   
    for (const auto& set : sets) {
        cout << "{";
        for (size_t i = 0; i < set.second.size(); i++) {
            cout << set.second[i];
            if (i != set.second.size() - 1) cout << ", ";
        }
        cout << "}" << endl;
    }
	return 0;
}