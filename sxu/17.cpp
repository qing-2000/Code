#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int triangle[101][101] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }
    for (int i = n-1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }
    cout << triangle[1][1] << endl;
    
    return 0;
}