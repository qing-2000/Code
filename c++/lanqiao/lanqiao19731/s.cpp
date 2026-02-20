#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define ll long long int

vector<ll> s;
vector<ll> t;
vector<ll> compare_arr; // 交替存储si,ti

void input(int n, vector<ll>& arr) { // 改为引用传递
    for(int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        arr.push_back(temp);
    }  
}

bool isInArr(ll num, vector<ll> arr) {
    for(auto& x : arr) {
        if(x == num) return true;
    }
    return false;
}

// 提取数字的所有数位
vector<int> getDigits(ll num) {
    vector<int> digits;
    if(num == 0) {
        digits.push_back(0);
        return digits;
    }
    while(num) {
        digits.push_back(num % 10);
        num /= 10;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

int check(ll num, vector<ll>& target_arr, int pos) {
    vector<int> num_digits = getDigits(num);
    
    // 检查目标数组中从pos+1位置开始的数字是否与当前数字有公共数位
    for(int i = pos + 1; i < target_arr.size(); i++) {
        vector<int> target_digits = getDigits(target_arr[i]);
        
        // 检查是否有公共数位
        for(int d1 : num_digits) {
            for(int d2 : target_digits) {
                if(d1 == d2 && (d1 == 0 || d1 == 2 || d1 == 4)) {
                    return i - pos; // 返回需要跳过的位置数
                }
            }
        }
    }
    return -1; // 没有找到连通
}

int main() {
    int n;
    cin >> n;
    input(n, s);
    input(n, t);
    
    int ans = 0; // 至少包含第一个符文石
    int term = 1; // 1表示当前在s数组，2表示在t数组
    int i = 0; // 当前在第一个数组中的位置
    
    while(i < n) {
        if(term == 1) { // 当前在s数组
            int skip = check(s[i], t, i);
            if(skip > 0) {
                ans += skip; // 增加连通长度
                i += skip;   // 跳过位置
                term = 2;    // 切换到t数组
            } else {
                break; // 无法继续连通
            }
        } else { // 当前在t数组
            int skip = check(t[i], s, i);
            if(skip > 0) {
                ans += skip; // 增加连通长度
                i += skip;   // 跳过位置
                term = 1;    // 切换到s数组
            } else {
                break; // 无法继续连通
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}