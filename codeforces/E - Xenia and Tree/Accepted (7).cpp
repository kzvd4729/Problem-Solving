/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/14/2018 15:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 499 ms                                          memory_used: 18100 KB                             
*  problem: https://codeforces.com/contest/342/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e8;
int n,m,sz[N+2],mark[N+2];
int anc[N+2],ans[N+2],tot;
int dist[22][N+2],level[N+2];
vector<int>adj[N+2];
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
void cal_dist(int node,int par,int cst,int lv)
{
  dist[lv][node]=cst;
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    cal_dist(x,node,cst+1,lv);
  }
}
void centroid(int node,int par,int lv)
{
  tot=0;reckon(node,-1);
  int center=find_center(node,par);
  anc[center]=par;mark[center]=1;
  level[center]=lv;
  cal_dist(center,-1,0,lv);
  for(auto x:adj[center])
  {
    if(mark[x])continue;
    centroid(x,center,lv+1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  centroid(1,-1,0);
  for(int i=1;i<=n;i++)ans[i]=inf;int tmp=1;
  while(tmp!=-1)
  {
    ans[tmp]=min(ans[tmp],dist[level[tmp]][1]);
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
        ans[nd]=min(ans[nd],dist[level[nd]][tmp]);
        nd=anc[nd];
      }
    }
    else
    {
      int tmp=nd,pr=inf;
      while(nd!=-1)
      {
        pr=min(pr,dist[level[nd]][tmp]+ans[nd]);
        nd=anc[nd];
      }
      cout<<pr<<endl;
    }
  }
  return 0;
}