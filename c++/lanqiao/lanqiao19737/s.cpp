#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        
        // 关键思维1: k-- 将问题分为前k-1个小组(保守构造)和第k个小组(特殊处理)
        k--; 
        
        // 使用map统计每个职业的总人数
        unordered_map<int, ll> profession;
        for (ll i = 0; i < n; ++i) {
            int a;
            ll b;
            cin >> a >> b;
            profession[a] += b;
        }
        
        ll totalSelected = 0;  // 总共需要选择的士兵数
        
        // 关键思维2: 按余数分类统计资源
        // remainder[3]: 能立即组成完整小组的资源(效率最高)
        // remainder[2]: 投入2人可获得潜力的资源  
        // remainder[1]: 投入1人可获得潜力的资源(效率最低)
        ll remainder[4] = {0};
        
        // 第一阶段: 建立基础保证 - 每个职业先固定选2人
        for (const auto &p : profession) {
            ll count = p.second;
            if (count < 3) {
                // 人数少于3，全选(无法组成小组，但必须包含)
                totalSelected += count;
            } else {
                // 关键思维3: 每个职业≥3人的，先固定选2人建立"存在性保证"
                // 这防止了敌人通过职业分布来卡我们
                totalSelected += 2; 
                count -= 2;  // 剩余可分配人数
                
                // 分类剩余资源的效率
                remainder[3] += count / 3;        // 每3人可立即组成1个小组
                remainder[count % 3] += 1;        // 按余数分类潜力资源
            }
        }
        
        // 第二阶段: 为前k-1个小组分配资源(保守构造)
        ll remainingTeams = k;  // 还需要构造的小组数
        
        // 关键思维4: 按效率优先级分配 - 3→2→1
        for (int efficiency = 3; efficiency > 0; --efficiency) {
            if (remainder[efficiency] == 0) continue;
            
            if (remainder[efficiency] <= remainingTeams) {
                // 当前效率等级的资源足够满足剩余需求
                totalSelected += efficiency * remainder[efficiency];
                remainingTeams -= remainder[efficiency];
                remainder[efficiency] = 0;
            } else {
                // 当前资源多于需求，只用一部分
                totalSelected += efficiency * remainingTeams;
                remainder[efficiency] -= remainingTeams;
                remainingTeams = 0;
                break;
            }
        }
        
        // 第三阶段: 处理第k个小组
        // 关键思维5: 如果前k-1个小组已完成且还有剩余资源
        // 那么第k个小组只需要再选1人(通过重新调整一定能组成)
        if (remainingTeams == 0) {
            // 检查是否还有剩余资源(任意类型)
            bool hasRemaining = false;
            for (int i = 1; i <= 3; i++) {
                if (remainder[i] > 0) {
                    hasRemaining = true;
                    break;
                }
            }
            
            if (hasRemaining) {
                // 关键思维6: 第k个小组只需要+1人
                // 因为前k-1个小组的保守构造已经创造了足够的调整空间
                cout << totalSelected + 1 << "\n";
            } else {
                // 没有剩余资源，无法组成第k个小组
                cout << "-1\n";
            }
        } else {
            // 前k-1个小组都无法完成，肯定无法组成k个小组
            cout << "-1\n";
        }
    }
    return 0;
}