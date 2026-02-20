#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int k;
    cin >> k;
    vector<int> arr(k);
    for (int i = 0; i < k; ++i) {
        cin >> arr[i];
    }
    
    vector<int> dp(k, 1); // dp[i]表示以第i个导弹结尾的最长不增子序列长度
    int ans = 1;
    for (int i = 1; i < k; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] >= arr[i]) { // 可以接在后面
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}