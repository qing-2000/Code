#include <iostream>
#include<vector>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n, a2, a3, a4, b4, b6;
    cin >> n;

    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> a2 >> a3 >> a4 >> b4 >> b6;
        int ans = 0;
        while (b6 > 0 && a3 >= 2) {

            b6--;
            a3 -= 2;
            ans += 6;
        }//2*3
        while (b6 > 0 && a2 > 0 && a4 > 0) {
            b6--;
            a2--;
            a4--;
            ans += 6;
        }//2+4
        while (b6 > 0 && a2 >= 3) {
            b6--;
            a2 -= 3;
            ans += 6;
        }//3*2
        while (b4 > 0 && a4 > 0) {
            b4--;
            a4--;
            ans += 4;
        }//4

        while (b4 > 0 && a2 >= 2) {
            b4--;
            a2 -= 2;
            ans += 4;
        }//2*2


        while (b6 > 0 && a4 > 0) {
            b6--;
            a4--;
            ans += 4;
        }//空6有4
        while (b6 > 0 && a3 > 0) {
            b6--;
            a3--;
            ans += 3;
        }//空6有3
        while (b4 > 0 && a3 > 0) {
            b4--;
            a3--;
            ans += 3;
        }//空4有3
        while (b6 > 0 && a2 > 0) {
            b6--;
            a2--;
            ans += 2;
        }//空6有2

        while (b4 > 0 && a2 > 0) {
            b4--;
            a2--;
            ans += 2;
        }//空4有2
        arr[i] = ans;
    }
    for (auto& n : arr)cout << n << endl;
    return 0;
}