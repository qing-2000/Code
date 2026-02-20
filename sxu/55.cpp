/*
可分割的背包问题，即允许取部分糖果。所以是分数背包。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Candy {
    int v, w;
    double ratio;
};

bool cmp(const Candy& a, const Candy& b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<Candy> candies(n);
    for (int i = 0; i < n; ++i) {
        cin >> candies[i].v >> candies[i].w;
        candies[i].ratio = (double)candies[i].v / candies[i].w;
    }
    sort(candies.begin(), candies.end(), cmp);
    double totalValue = 0.0;
    int remain = W;
    for (int i = 0; i < n && remain > 0; ++i) {
        if (candies[i].w <= remain) {
            totalValue += candies[i].v;
            remain -= candies[i].w;
        } else {
            totalValue += candies[i].ratio * remain;
            remain = 0;
        }
    }
    cout << fixed << setprecision(1) << totalValue << endl;
    return 0;
}