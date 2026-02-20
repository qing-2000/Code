
#include <iostream>
using namespace std;
const int N = 10e5;
int a[N];

int main()
{
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[j] + a[i];
                a[j] = temp - a[j];
                a[i] = temp - a[i];
            }
        }
        cout << a[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                temp = a[j] + a[i];
                a[j] = temp - a[j];
                a[i] = temp - a[i];
            }
        }
        cout << a[i];
    }
    return 0;
}