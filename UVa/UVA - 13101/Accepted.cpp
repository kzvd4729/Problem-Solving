/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-13 00:51:03                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 110                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-13101
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e4;
int t,n,cost[N+2],sz[N+2],seg[5*N+2],parent[N+2];
int level[N+2],tim,st[N+2],anc[N+2],tc;
vector<int>adj[N+2];
void upd(int node,int lo,int hi,int id,int vl)
{
  if(lo==hi)
  {
    seg[node]=vl;return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);
  seg[node]=__gcd(seg[node*2],seg[node*2+1]);
}
int query(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  return __gcd(query(node*2,lo,md,lt,rt),query(node*2+1,md+1,hi,lt,rt));
}
void dfs(int node,int par,int h)
{
  level[node]=h,parent[node]=par;
  for(int i=0;i<adj[node].size();i++)
  {
    int xx=adj[node][i];if(xx==par)continue;
    dfs(xx,node,h+1);sz[node]+=sz[xx];
    if(sz[xx]>=sz[adj[node][0]])swap(adj[node][i],adj[node][0]);
  }
}
void hld(int node,int par)
{
  ++tim;st[node]=tim;upd(1,1,n,tim,cost[node]);
  for(int i=0;i<adj[node].size();i++)
  {
    int xx=adj[node][i];if(xx==par)continue;
    anc[xx]=(xx==adj[node][0]?anc[node]:xx);hld(xx,node);
  }
}
int _query(int u,int v)
{
  int sum=0;
  while(anc[u]!=anc[v])
  {
    if(level[anc[u]]<level[anc[v]])swap(u,v);
    sum=__gcd(sum,query(1,1,n,st[anc[u]],st[u]));
    u=parent[anc[u]];
  }
  return __gcd(sum,query(1,1,n,min(st[u],st[v]),max(st[u],st[v])));
}
int main()
{
  while(scanf("%d",&n)==1)
  {
    for(int i=0;i<n;i++)adj[i].clear();
    for(int i=0;i<n;i++)
      scanf("%d",&cost[i]);
    for(int i=1;i<n;i++)
    {
      int u,v;scanf("%d%d",&u,&v);
      adj[u].push_back(v);adj[v].push_back(u);
    }
    memset(seg,0,sizeof(seg));
    tim=0;dfs(0,-1,0);hld(0,-1);
    int q;scanf("%d",&q);
    while(q--)
    {
      int ty,u,v;scanf("%d%d%d",&ty,&u,&v);
      if(ty==2)upd(1,1,n,st[u],v);
      else printf("%d\n",_query(u,v));
    }
  }
  return 0;
}