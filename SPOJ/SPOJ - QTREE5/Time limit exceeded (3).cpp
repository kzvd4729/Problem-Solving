/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-14 12:26:30                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-QTREE5
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e9;
int n,sz[N+2],mark[N+2],tot;
int anc[N+2];
vector<int>adj[N+2];
multiset<int>st[N+2];
unordered_map<int,int>dist[N+2];
int dfs(int node,int par)
{
  tot++;sz[node]=1;
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    sz[node]+=dfs(x,node);
  }
}
int find_center(int node,int par)
{
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
  tot=0;dfs(node,-1);
  int center=find_center(node,-1);
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
  cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  centroid(1,-1);int q;cin>>q;
  for(int i=1;i<=n;i++)st[i].insert(inf);
  while(q--)
  {
    int ty,nd,tmp;cin>>ty>>nd;tmp=nd;
    if(!ty)
    {
      if(st[nd].find(0)==st[nd].end())
      {
        while(nd!=-1)
        {
          st[nd].insert(dist[nd][tmp]);
          nd=anc[nd];
        }
      }
      else
      {
        while(nd!=-1)
        {
          st[nd].erase(st[nd].find(dist[nd][tmp]));
          nd=anc[nd];
        }
      }
    }
    else
    {
      int pr=inf;
      while(nd!=-1)
      {
        pr=min(pr,*st[nd].begin()+dist[nd][tmp]);
        nd=anc[nd];
      }
      if(pr==inf)pr=-1;
      cout<<pr<<endl;
    }
  }
  return 0;
}