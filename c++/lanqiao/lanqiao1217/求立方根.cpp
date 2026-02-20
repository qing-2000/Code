#include <bits/stdc++.h>
using namespace std;
#define double long double

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    double  a;
    vector<double>b(n);
    for (int i = 0; i < n; i++) {
        cin >> a;

        double left = 0, right = a, mid, ans=-1;
        while (left <= right) {
            mid = (right + left) / 2;
            double cube = mid * mid * mid;
            if (abs(cube - a) < 1e-12) {
                ans = mid;
                break;
            }
            if (cube < a) {
                left = mid + 0.0001;
                ans = mid;
            }
            if (cube > a) {
                right = mid - 0.0001;
                ans = mid;
            }
        }
        printf("%.3lf\n", ans);
    }

    return 0;
}
