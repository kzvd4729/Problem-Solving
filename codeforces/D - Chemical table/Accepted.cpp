/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/30/2018 16:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 15900 KB                             
*  problem: https://codeforces.com/contest/1013/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e8;
const int N=2e5;
int n,m,q,u,v,ans,vis[N+2],com;
int visr[N+2],visc[N+2];
vector<int>adjr[N+2],adj[N+2];
void dfs(int node)
{
  vis[node]=1;
  for(auto xx:adj[node])
  {
    if(vis[xx])continue;
    dfs(xx);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m>>q;
  while(q--)
  {
    cin>>u>>v;
    visr[u]=1;
    visc[v]=1;
    adjr[u].push_back(v);
  }
  if(q==0)cout<<n+m-1<<endl,exit(0);
  if(q==1)cout<<n+m-2<<endl,exit(0);
   if(n==1)
  {
    for(int i=1;i<=m;i++)
      if(visc[i]==0)ans++;
    cout<<ans<<endl,exit(0);
  }
  if(m==1)
  {
    for(int i=1;i<=n;i++)
      if(visr[i]==0)ans++;
    cout<<ans<<endl,exit(0);
  }
  for(int i=1;i<=n;i++)
    if(visr[i]==0)ans++;
  for(int i=1;i<=m;i++)
    if(visc[i]==0)ans++;
  for(int i=1;i<=n;i++)
  {
    if(adjr[i].size()==0)
      continue;
    else if(adjr[i].size()==1)
    {
      adj[adjr[i][0]].push_back(adjr[i][0]);
    }
    else
    {
      for(int j=0;j<adjr[i].size()-1;j++)
      {
        int on=adjr[i][j];
        int tw=adjr[i][j+1];
        adj[on].push_back(tw);
        adj[tw].push_back(on);
      }
    }
  }
  for(int i=1;i<=m;i++)
  {
    if(vis[i]||adj[i].size()==0)continue;
    dfs(i);
    com++;
  }
  cout<<ans+com-1<<endl;
  return 0;
}