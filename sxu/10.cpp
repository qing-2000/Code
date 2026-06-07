#include <iostream>
using namespace std;

int josephus(int n, int m) {
    int result = 0;
    for (int i = 2; i <= n; i++) {
        result = (result + m) % i;
    }
    return result + 1;
}

int main() {
    int n, m;
    
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;  // 结束输入
        }
        
        cout << josephus(n, m) << endl;
    }
    
    return 0;
}