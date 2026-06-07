#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double EPS = 1e-6;

bool isZero(double x) {
    return fabs(x) < EPS;
}

bool canGet24(vector<double>& nums) {
    int n = nums.size();
    if (n == 1) {
        return fabs(nums[0] - 24.0) < EPS;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double a = nums[i], b = nums[j];
            // 剩余的数
            vector<double> rest;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) rest.push_back(nums[k]);
            }
            
            // 尝试所有可能的运算结果
            vector<double> results;
            results.push_back(a + b);
            results.push_back(a - b);
            results.push_back(b - a);
            results.push_back(a * b);
            if (!isZero(b)) results.push_back(a / b);
            if (!isZero(a)) results.push_back(b / a);
            
            for (double res : results) {
                rest.push_back(res);
                if (canGet24(rest)) return true;
                rest.pop_back();
            }
        }
    }
    return false;
}

int main() {
    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        if (a == 0 && b == 0 && c == 0 && d == 0) break;
        vector<double> nums = {(double)a, (double)b, (double)c, (double)d};
        if (canGet24(nums)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}