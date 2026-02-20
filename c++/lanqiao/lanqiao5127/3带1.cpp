#include <iostream>
#include <cstring>
#include <algorithm>
#include<string>
using namespace std;
struct node {
    char name;
    int data;
};
int main() {
    int n;
    cin >> n;
    cin.ignore();
    struct node arr[13] = {
      {'A',0},{'2',0},{'3',0},{'4',0},{'5',0},{'6',0},{'7',0},{'8',0},{'9',0},{'X',0},{'J',0},{'Q',0},{'K',0}
    };
    bool BO[60] = { false };
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        sort(s.begin(), s.end());
        for (int k = 0; k < 4; k++) {
            for (int j = 0; j < 13; j++) {
                if (s[k] == arr[j].name)arr[j].data++;
            }
        }
        for (auto& n : arr)if (n.data == 3) { BO[i] = true; break; }
        for (auto& n : arr)n.data = 0;
    }
    for (int i = 0; i < n; i++)if (BO[i])cout << "Yes" << endl; else cout << "No" << endl;
    return 0;
}