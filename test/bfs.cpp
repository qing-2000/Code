#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[3][3];
int dir[4][2]={
    {-1,0},
    {0,-1},
    {1,0},
    {0,1}
};
struct node{
    int x,y,dist;
    node(int _x,int _y,int _dist):x(_x),y(_y),dist(_dist){};
};
bool isLigal(int x, int y)
{
    return x > -1 && x < 3 && y > -1 && y < 3;
}
bool visited[3][3] = {false};
int ans = 0;
queue<node> q;
int bfs(int source, int target)
{
    while (!q.empty())
    {
        q.pop();
    }
    int sx=-1,sy=-1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(map[i][j]==source){
                sx=i;
                sy=j;
                break;
            }
        }
    }
    if(sx==-1||sy==-1)return -1;
    if (map[sx][sy] == target)
    {
        visited[sx][sy]=true;
        return ans;
    }
    if (isLigal(sx, sy) && visited[sx][sy] != true)
    {
        q.push(node(sx,sy,0));
        visited[sx][sy] = true;
    }
    while (!q.empty())
    {
        node current=q.front();
        if(map[current.x][current.y]==target){
        
            return current.dist;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int t1 = current.x + dir[i][0];
            int t2 = current.y + dir[i][1];
            if (isLigal(t1, t2) && visited[t1][t2] != true)
            {
                q.push(node(t1,t2,current.dist+1));
                visited[t1][t2] = true;
            }
        }
    }
    return -1;
}
int main()
{
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>map[i][j];
        }
    }
    int source,target;
    cin>>source>>target;
    ans=bfs(source,target);
    cout<<ans;
    return 0;
}