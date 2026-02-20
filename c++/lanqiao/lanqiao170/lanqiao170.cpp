#include <iostream>
#include<string>

#include<algorithm>
using namespace std;
int main()
{
    // 请在此输入您的代码
    string s;
    getline(cin, s);
    int a[26] = { 0 }, b[26] = { 0 };

    for (int i = 0; i < s.size(); i++) {
        a[s[i] - 'a']++;
    }
    int max = 0, min = 0, temp = 0;
    for (int i = 0; i < 26; i++) {
        if (a[i] > 0)b[temp++] = a[i];
    }
    b[temp] = 0;
    sort(b, b + 26,[](int a,int b) {
        return a > b;
        });
  for (int i = 0; i < temp; i++) {
      max = max > b[i] ? max : b[i];
      if (min == 0) {
          min = b[i];
      }
      else min = min < b[i] ? min : b[i];
      
  }
    
  
  cout<<max-min;
  return 0;
}
