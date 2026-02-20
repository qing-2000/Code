//先总时间大小排序，在1.2位时间大小排序。
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;

struct tim {
    ll x, y, z;
    ll sum() const { return x + y + z; }
};

bool cmp(const tim& a, const tim& b) {
    if (a.sum() == b.sum()) return (a.x + a.y) < (b.x + b.y);
    return a.sum() < b.sum();
}

int main() {
    int n;
    cin >> n;

    tim arr[1000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
    }

    // 使用std::sort配合自定义比较器
    sort(arr, arr + n, cmp);

    ll ans = 0, time = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            time = arr[i].x + arr[i].y;
        }
        else {
            time += arr[i].x + arr[i].y + arr[i - 1].z;
        }
        ans += time;
    }

    cout << ans << endl;
    return 0;
}