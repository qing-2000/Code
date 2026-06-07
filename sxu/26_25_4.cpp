//约瑟夫问题
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> vis(m, 0);
    vector<int> res;

    int count = 0;
    int i = 0;

    while(res.size() < m){

        if(vis[i] == 0){
            count++;

            if(count == n){
                res.push_back(i+1);
                vis[i] = 1;
                count = 0;
            }
        }

        i = (i + 1) % m;
    }

    for(int j=0;j<res.size();j++){
        if(j) cout<<" ";
        cout<<res[j];
    }
}