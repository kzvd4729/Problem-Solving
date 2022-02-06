/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/14/2018 00:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1435 ms                                         memory_used: 101900 KB                            
*  problem: https://codeforces.com/contest/342/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e8;
int n,m,sz[N+2],mark[N+2];
int anc[N+2],ans[N+2],tot;
vector<int>adj[N+2];
unordered_map<int,int>dist[N+2];
int reckon(int node,int par)
{
  tot++;sz[node]=1;
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    sz[node]+=reckon(x,node);
  }
  return sz[node];
}
int find_center(int node,int par)
{
  int mx=-1,nx=-1;
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    if(sz[x]>tot/2)return find_center(x,node);
  }
  return node;
}
void cal_dist(int center,int node,int par,int lv)
{
  dist[center][node]=dist[node][center]=lv;
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    cal_dist(center,x,node,lv+1);
  }
}
void centroid(int node,int par)
{
  tot=0;reckon(node,-1);
  int center=find_center(node,par);
  anc[center]=par;mark[center]=1;
  cal_dist(center,center,-1,0);
  for(auto x:adj[center])
  {
    if(mark[x])continue;
    centroid(x,center);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=1;i<=n;i++)
  {
    dist[i].max_load_factor(0.25);
    dist[i].reserve(1024);
  }
  cin>>n>>m;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  centroid(1,-1);
  for(int i=1;i<=n;i++)ans[i]=inf;int tmp=1;
  while(tmp!=-1)
  {
    ans[tmp]=min(ans[tmp],dist[tmp][1]);
    tmp=anc[tmp];
  }
  while(m--)
  {
    int ty,nd;cin>>ty>>nd;
    if(ty==1)
    {
      int tmp=nd;
      while(nd!=-1)
      {
        ans[nd]=min(ans[nd],dist[nd][tmp]);
        nd=anc[nd];
      }
    }
    else
    {
      int tmp=nd,pr=inf;
      while(nd!=-1)
      {
        pr=min(pr,dist[nd][tmp]+ans[nd]);
        nd=anc[nd];
      }
      cout<<pr<<endl;
    }
  }
  return 0;
}