#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> ans;
    int N,num,sum=0;
    while (true) {
        
        cin >> N;
        if (N == 0) {
            break;
        }
        
        sum = 0;
        for (int i = 0; i < N; i++) {
            cin >> num;
            sum += num;
        }
        
        ans.push_back(sum);
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}