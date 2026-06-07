#include<iostream>
#include<numeric>  // 包含 gcd 和 lcm
#include<vector>
using namespace std;

int main() {
    int k;
    cin >> k;
    
    for (int i = 0; i < k; i++) {
        int n, m;
        cin >> n >> m;
        
        int g = gcd(n, m);  // C++17 标准库函数
        int l = lcm(n, m);  // C++17 标准库函数
        
        cout << g << " " << l << endl;
    }
    
    return 0;
}
/*
#include<iostream>
#include<vector>
using namespace std;

// 最大公约数（欧几里得算法）
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 最小公倍数
int lcm(int a, int b) {
    return a / gcd(a, b) * b;  // 先除后乘，避免溢出
}

int main() {
    int k;
    cin >> k;
    
    vector<pair<int, int>> results(k);  // first: gcd, second: lcm
    
    for (int i = 0; i < k; i++) {
        int n, m;
        cin >> n >> m;
        
        int g = gcd(n, m);
        int l = lcm(n, m);
        
        results[i] = make_pair(g, l);  // 按题目要求顺序存储
    }
    
    // 输出
    for (int i = 0; i < k; i++) {
        cout << results[i].first << " " << results[i].second << endl;
    }
    
    return 0;
}
*/