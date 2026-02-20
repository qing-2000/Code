#include <bits/stdc++.h>
using namespace std;
#define int long long   // 定义 int 为 long long 类型，避免可能的溢出
#define ld long double  // 定义 ld 为 long double 类型，用于更精确的浮点运算

ld n, res, p, mi = 1e15;  // 定义变量：n 为宠物数量，res 为结果（最优分组数），p 为每只宠物被感染的概率，mi 用于记录最小的期望值，初始化为一个很大的值

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);  // 提高输入输出效率
    cin >> n >> p;  // 输入宠物数量 n 和感染概率 p

    // 遍历可能的分组数 k，从 2 到 n
    for (int k = 2; k <= n; k++)
    {
        if ((int)n % k != 0)  // 如果 n 不能被 k 整除，跳过该 k
            continue;

        // 计算期望消耗量 E
        ld E = (n / (ld)k) * (pow(1.0 - p, k) + (1.0 - pow(1.0 - p, k)) * (k + 1));
        // 计算每个分组数 k 对应的期望值，公式涉及概率和每个分组内的操作

        if (E < mi)  // 如果当前期望值 E 小于最小的期望值 mi
        {
            res = k;  // 更新最优的分组数 k
            mi = E;   // 更新最小的期望值
        }
    }

    if (n < mi)  // 如果 n 本身的期望值小于 mi，则返回 1，表示不需要分组
        res = 1;

    cout << res << endl;  // 输出最优分组数 k
    return 0;  // 返回 0，表示程序成功结束
}
