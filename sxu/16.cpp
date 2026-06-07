#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());
    s2.erase(remove(s2.begin(), s2.end(), ' '), s2.end());
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    
    if (s1 == s2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}