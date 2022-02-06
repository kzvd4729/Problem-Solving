/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/07/2019 11:59                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 966 ms                                          memory_used: 58900 KB                             
*  problem: https://codeforces.com/contest/732/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=4e5;
int vis[N+2],level[N+2],sz;
vector<int>adj[N+2],spt[N+2],ex[N+2],brd[N+2],ed[N+2];
vector<pair<int,int> >eg,ok;
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
    brd[node].push_back(par);
    brd[par].push_back(node);
  }
  return mn;
}
void visit(int node)
{
  sz++;vis[node]=1;
  for(auto x:adj[node])
  {
    if(vis[x])continue;
    if(binary_search(brd[node].begin(),brd[node].end(),x))continue;
    visit(x);
  }
}
void mxcmp(int node,int par)
{
  if(vis[node])return ;vis[node]=1;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(binary_search(brd[node].begin(),brd[node].end(),x))
      {ok.push_back({node,x});continue;}
    ed[node].push_back(x);mxcmp(x,node);
  }
}
void mncmp(int node,int par)
{
  if(vis[node])return ;vis[node]=1;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    ed[x].push_back(node);mncmp(x,node);
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
  for(int i=1;i<=n;i++)
    sort(brd[i].begin(),brd[i].end());
   memset(vis,0,sizeof(vis));
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;sz=0;
    visit(i);if(sz>mxsz)mxsz=sz,rt=i;
  }
  memset(vis,0,sizeof(vis));
  mxcmp(rt,-1);
  for(auto x:ok)
  {
    ed[x.second].push_back(x.first);
    mncmp(x.second,x.first);
  }
  cout<<mxsz<<"\n";
  for(int i=1;i<=n;i++)
    sort(ed[i].begin(),ed[i].end());
  for(auto x:eg)
  {
    if(binary_search(ed[x.first].begin(),ed[x.first].end(),x.second))
      cout<<x.first<<" "<<x.second<<"\n";
    else cout<<x.second<<" "<<x.first<<"\n";
  }
  return 0;
}