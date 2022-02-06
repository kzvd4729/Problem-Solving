/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/14/2019 18:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 374 ms                                          memory_used: 40400 KB                             
*  problem: https://codeforces.com/contest/1276/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int vis[N+2],aa[3][N+2];
vector<int>adj[N+2];
void dfs(int node,int i)
{
  vis[node]=1;aa[i][node]=1;
  for(auto x:adj[node])
    if(!vis[x])dfs(x,i);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,a,b;cin>>n>>m>>a>>b;
    for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=1;i<=m;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)aa[1][i]=0,aa[2][i]=0;
    for(int i=1;i<=n;i++)vis[i]=0;
    vis[b]=1;dfs(a,1);
    for(int i=1;i<=n;i++)vis[i]=0;
    vis[a]=1;dfs(b,2);
     int sza=-1,szb=-1;
    for(int i=1;i<=n;i++)
    {
      if(aa[1][i]&&(!aa[2][i]))sza++;
      if(!(aa[1][i])&&aa[2][i])szb++;
    }
    long ans=(1LL*sza*szb);cout<<ans<<"\n";
  }
  return 0;
}