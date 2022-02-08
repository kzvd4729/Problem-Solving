/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-12 22:11:12                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 2103 ms                                         memory_used: 95360 KB                             
*  problem: https://atcoder.jp/contests/abc142/tasks/abc142_f
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<int>adj[N+2];
vector<pair<int,int> >bk;
int vis[N+2],lev[N+2],in[N+2],prnt[N+2];
void dfs(int node,int par,int lv)
{
  vis[node]=1,lev[node]=lv;prnt[node]=par;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(vis[x])bk.push_back({node,x});
    else dfs(x,node,lv+1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);in[v]++;
  }
  for(int i=1;i<=n;i++)
    if(in[i]==0)dfs(i,-1,1);
  for(int i=1;i<=n;i++)
    if(!vis[i])dfs(i,-1,1);
  int mn=n+1,u,v;
  for(auto x:bk)
  {
    int df=lev[x.first]-lev[x.second];
    if(df>0&&df<mn)mn=df,u=x.first,v=x.second;
  }
  if(mn>n)cout<<-1<<endl,exit(0);
  cout<<mn+1<<"\n";
  while(true)
  {
    cout<<u<<"\n";if(u==v)break;
    u=prnt[u];
  }
  return 0;
}