#include <iostream>
#include<string>
#include<vector>
#include<stdio.h>
using namespace std;
int d_num;//地雷图数
char str[100][100];//记录地图情况,仅'0-8'及'*'组成
int record[100][100] = { 0 };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };//方向
int n, m;//行，列
int res;//纪录地雷数
vector<string> ans; //答案,唯一解为simple，多解为multiple
int c = 0;
void setArr(int a[100][100]) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++)
            a[i][j] = 1;
    }
}//完全访问
void initarr(int a[100][100]) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++)
            a[i][j] = 0;
    }
}//清空记录数组
bool check(int a[100][100]) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (a[i][j] != 1)return false;//没有访问完，返回false；
        }
    }
    return true;
}
bool checkpoint(int a, int b) {
    for (int i = 0; i < 4; i++) {
        int p = a + i, q = b + i;
        if (str[p][q] - '0' == 0)return false;//未知点上下左右均非0
    }
}
void initbrr(char str[100][100]) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++)
            str[i][j] = '0';
    }
}//清空地图数组
void dfs(int locationx, int locationy) {
    
    if (locationx < 0 || locationx >= n || locationy < 0 || locationy >= m || record[locationx][locationy] == 1)return;//越界或有雷或已访问返回
    
    record[locationx][locationy] = 1;
    
    if (str[locationx][locationy] != '*' ) {//非雷区 
        if (((locationx - 1) >= 0) && ((locationy - 1) >= 0) && str[locationx - 1][locationy - 1] == '*')res++;//左上
        
        if (((locationy - 1) >= 0) && str[locationx][locationy - 1] == '*')res++;//左
        
        if (((locationx + 1) < n) && ((locationy - 1) >= 0) && str[locationx + 1][locationy - 1] == '*')res++;//左下
       
        if (((locationx - 1) >= 0) && ((locationy + 1) < m) && str[locationx - 1][locationy + 1] == '*')res++;//右上
        
        if (((locationy + 1) < m) && str[locationx][locationy + 1] == '*')res++;//右
        
        if (((locationx + 1) <= n) && ((locationy + 1) < m) && str[locationx + 1][locationy + 1] == '*')res++;//右下
        
        if (((locationx - 1) >= 0) && str[locationx - 1][locationy] == '*')res++;//上
        
        if (((locationx + 1) < n) && str[locationx + 1][locationy] == '*')res++;//下
        
        if (res > str[locationx][locationy]-'0') {//未知点数大于雷数
            ans.push_back ( "mutiple");
            setArr(record);//跳过
            return;
        }
        res = 0;//重置res以记录每个位置
    }//如果为数字，判断其周围（九宫格内）是否存在多个雷
    for (int i = 0; i < 4; i++) {//搜索
        int x = locationx + dx[i];
        int y = locationy + dy[i];
        dfs(x, y);
    }
    if (check(record)) {//均已访问
        if(ans.size()<c)ans.push_back("simple");
        return ;
    }
}

int main()
{
    // 请在此输入您的代码
    cin >> d_num;
    
   

    while(c<d_num){
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)cin >> str[i][j];//创建多个迷宫
    dfs(0, 0);//从0开始
    c++;
    initarr(record);//清空，便于后续地图计录
    initbrr(str);//清空，便于更新地图
    }
    
    for (auto& a : ans)cout << a << endl;
    return 0;
}
