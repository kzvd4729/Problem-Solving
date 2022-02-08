/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-09-01 19:00:15                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 274 ms                                          memory_used: 51072 KB                             
*  problem: https://atcoder.jp/contests/abc139/tasks/abc139_e
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int mt[N+2][N+2],cnt,f,dp[N*N+2],vis[N*N+2];
vector<int>adj[N*N+2];
void con(int n)
{
  cnt=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      mt[i][j]=mt[j][i]=++cnt;
    }
  }
}
void findCycle(int nd)
{
  if(vis[nd]==1){f=1;return ;}
  if(vis[nd])return ;vis[nd]=1;
  for(auto x:adj[nd])
    findCycle(x);
  vis[nd]=2;
}
void dfs(int nd)
{
  if(dp[nd]!=-1)return ;
  dp[nd]=1;
  for(auto x:adj[nd])
  {
    dfs(x);
    dp[nd]=max(dp[nd],dp[x]+1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;con(n);
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;int nd=mt[i][x];
    for(int j=1;j<=n-2;j++)
    {
      cin>>x;adj[nd].push_back(mt[i][x]);
      nd=mt[i][x];
    }
  }
  for(int i=1;i<=cnt;i++)
  {
    findCycle(i);
    if(f)cout<<"-1"<<endl,exit(0);
  }
  memset(dp,-1,sizeof(dp));
  for(int i=1;i<=cnt;i++)
    dfs(i);
  int mx=0;
  for(int i=1;i<=cnt;i++)
    mx=max(mx,dp[i]);
  cout<<mx<<endl;
  return 0;
}