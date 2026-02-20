#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100003;
int a[N];
int s[N];

struct Edge{
  int x,y,w;
  Edge(int x_,int y_,int w_):x(x_),y(y_),w(w_){}
};
int find(int i){
  if(a[i]!=i){
    a[i]=find(a[i]);
  }
  return a[i];
}
int main()
{
  int n,m,l,r;
  long long  ant=0;
  vector<Edge> edges;
  cin>>n>>m>>l>>r;
  for(int i=0;i<n;i++){
    a[i]=i;
    s[i]=1;
  }
  int x,y,w;
  for(int i=0;i<m;i++){
    cin>>x>>y>>w;
    edges.emplace_back(x,y,w);
  }
  //从小到大排序，为了先将小于l的点使用并查集合并成一个点集。然后再对[l,r]之间的点进行配对得到答案，最后舍弃大于r的点
  sort(edges.begin(),edges.end(),[](const Edge& a,const Edge& b){
      return a.w<b.w;
  });

  for(int i=0;i<edges.size();i++){
       Edge edge = edges[i];
       if(edge.w>r)break;//大于r舍弃
      int fa=find(edge.x);
      int fb =find(edge.y);
      if(fa!=fb){
        if(edge.w>=l&&edge.w<=r){//满足条件的计算结果，在满足条件之前都在进行缩点
         ant+=(long long)s[fa]*s[fb];
        }
         a[fb]=fa;
         s[fa]+=s[fb];
      }
  }
  cout<<ant<<endl;
  return 0;
}