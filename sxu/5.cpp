#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    double e = 1.0, f = 1.0;
    for (int i = 1; i <= n; i++) {
        f *= i;
        e += 1.0 / f;
    }
    
    printf("%.10f\n", e);
    return 0;
}