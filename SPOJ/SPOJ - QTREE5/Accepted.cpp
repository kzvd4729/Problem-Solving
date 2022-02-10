/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-14 15:47:46                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 710                                        memory_used (MB): 60.4                            
*  problem: https://vjudge.net/problem/SPOJ-QTREE5
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e9;
int n,sz[N+2],mark[N+2],tot,level[N+2];
int anc[N+2],col[N+2],dist[20][N+2];
vector<int>adj[N+2];
multiset<int>st[N+2];
void dfs(int node,int par)
{
  tot++;sz[node]=1;
  for(auto x:adj[node])
  {
    if(x==par||mark[x])continue;
    dfs(x,node);sz[node]+=sz[x];
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
  tot=0;dfs(node,-1);
  int center=find_center(node,-1);
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
  scanf("%d",&n);
  for(int i=1;i<n;i++)
  {
    int u,v;scanf("%d%d",&u,&v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  centroid(1,-1,1);int q;scanf("%d",&q);
  for(int i=1;i<=n;i++)st[i].insert(inf);
  while(q--)
  {
    int ty,nd,tmp;scanf("%d%d",&ty,&nd);tmp=nd;
    if(!ty)
    {
      if(!col[nd])
      {
        col[nd]=1;
        while(nd!=-1)
        {
          st[nd].insert(dist[level[nd]][tmp]);
          nd=anc[nd];
        }
      }
      else
      {
        col[nd]=0;
        while(nd!=-1)
        {
          st[nd].erase(st[nd].find(dist[level[nd]][tmp]));
          nd=anc[nd];
        }
      }
    }
    else
    {
      int pr=inf;
      while(nd!=-1)
      {
        pr=min(pr,*st[nd].begin()+dist[level[nd]][tmp]);
        nd=anc[nd];
      }
      if(pr==inf)pr=-1;
      printf("%d\n",pr);
    }
  }
  return 0;
}