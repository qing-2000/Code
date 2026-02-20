#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int N, S0 = 0, S1 = 0, T0 = 0, T1 = 0, sum = 0;
    cin >> N;
    cin.ignore();
    vector<char> S(N), T(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        if (S[i] == '0') S1++;
        else S0++;
    }
    for (int i = 0; i < N; i++) {
        cin >> T[i];
        if (T[i] == '0') T1++;
        else T0++;
    }
    while (S1 > 0 && T0 > 0) {
        S1--;
        T0--;
        sum++;
    }
    while (S0 > 0 && T1 > 0) {
        S0--;
        T1--;
        sum++;
    }
    cout << sum;
    return 0;
}