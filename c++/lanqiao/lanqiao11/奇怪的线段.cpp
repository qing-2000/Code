//60%超时
#include <iostream>

using namespace std;

struct node {
    int x, y;
};

int main() {
    int n, q;
    cin >> n >> q;
    //本地运行时将数组大小缩小到2000
    struct node arr[2000];  // 存储节点
    int ans[2000] = { 0 }, temp1, temp2;

    
    // 输入节点的坐标
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    // 处理每个查询
    for (int i = 0; i < q; i++) {
        cin >> temp1 >> temp2;
        for (int j = 0; j < n; j++) {
            // 判断条件
            if (arr[j].x <= temp1 && arr[j].y >= temp1 && (arr[j].y < temp2 || arr[j].x > temp2)) {
                ans[i]++;  // 累加满足条件的节点
            }
        }
    }
  

    // 输出每个节点的答案
    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
