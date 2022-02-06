/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/07/2019 11:43                        
*  solution_verdict: Memory limit exceeded on test 1         language: GNU C++14                               
*  run_time: 265 ms                                          memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/732/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int N=1e6;
int vis[N+2],level[N+2],sz;
vector<int>adj[N+2],spt[N+2],ex[N+2],ok;
gp_hash_table<int,int>brd[N+2],ed[N+2];
vector<pair<int,int> >eg;
void dfs(int node,int par,int lv)
{
  vis[node]=1;level[node]=lv;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(vis[x])
    {
      ex[node].push_back(x);
      ex[x].push_back(node);
    }
    else
    {
      spt[node].push_back(x);
      spt[x].push_back(node);
      dfs(x,node,lv+1);
    }
  }
}
int bridges(int node,int par)
{
  int mn=1e9;
  for(auto x:spt[node])
  {
    if(x==par)continue;
    mn=min(mn,bridges(x,node));
  }
  for(auto x:ex[node])
    mn=min(mn,level[x]);
  if(mn>=level[node]&&par!=-1)
  {
    brd[node][par]=1;
    brd[par][node]=1;
  }
  return mn;
}
void visit(int node)
{
  sz++;vis[node]=1;
  for(auto x:adj[node])
  {
    if(vis[x])continue;
    if(brd[node][x])continue;
    visit(x);
  }
}
void mxcmp(int node)
{
  for(auto x:adj[node])
  {
    if(brd[node][x])
      {ok.push_back(node);continue;}
    if(ed[node][x])continue;
    if(ed[x][node])continue;
    ed[node][x]=1;mxcmp(x);
  }
}
void mncmp(int node)
{
  for(auto x:adj[node])
  {
    if(ed[node][x])continue;
    if(ed[x][node])continue;
    ed[x][node]=1;mncmp(x);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    eg.push_back({u,v});
  }
  dfs(1,-1,0);
  bridges(1,-1);int mxsz=0,rt;
  memset(vis,0,sizeof(vis));
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;sz=0;
    visit(i);if(sz>mxsz)mxsz=sz,rt=i;
  }
  mxcmp(rt);for(auto x:ok)mncmp(x);
  cout<<mxsz<<"\n";
  for(auto x:eg)
  {
    if(ed[x.first][x.second])
      cout<<x.first<<" "<<x.second<<"\n";
    else cout<<x.second<<" "<<x.first<<"\n";
  }
  return 0;
}