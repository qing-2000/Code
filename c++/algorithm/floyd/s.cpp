#include<iostream>
#include<vector>
#include<climits>
using namespace std;
const int INF = 1e9;
int n,m,A,B;//n节点，m边

void floyd(int n,vector<vector<int>>& dist){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k] < INF && dist[k][j] < INF){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                    
                }
            }
        }
    }
}
int find(int a,int b,vector<vector<int>>& dist){
    if(dist[a][b]!=INF) return dist[a][b];
    return -1;
}
void print(int n, vector<vector<int>>& dist) {  // 需要传入n和dist
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] == INF) 
                cout << "INF ";
            else 
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    
    cin>>n>>m;

    //init
    vector<vector<int>> dist(n,vector<int>(n,INF));
    for(int i=0;i<n;i++){
        dist[i][i]=0;//自己距自己0,权重
    }

    for(int i=0;i<m;i++){
        int u,v,w;//点，点，权重
        cin>>u>>v>>w;
        //dist[u][v]=min(dist[u][v],w);//处理重边,有向图处理逻辑
        dist[u][v]=min(dist[u][v],w);//无向图处理逻辑
        dist[v][u]=min(dist[v][u],w);
    }
    cout<<"修改前："<<endl;
    print(n,dist);

    floyd(n,dist);//floyd处理最短路径

    cout<<"修改后："<<endl;
    print(n,dist);
    cout<<"请输入要查询最短路径的起点和终点：";
    cin>>A>>B;
    int ans=find(A,B,dist);//查询floyd处理后的A-B最短路径
    cout<<endl;
    cout<<"起点："<<A<<"到终点："<<B<<"的最短路径为："<<ans;

    return 0;
}