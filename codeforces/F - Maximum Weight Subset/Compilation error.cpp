/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/23/2019 01:16                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1249/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e2;
int aa[N+2],k,a[N+2],b[N+2],dp[N+2][N+2],rm[N+2][N+2],qm[N+2][N+2];
vector<int>adj[N+2];
int dfs(int node,int par,int d)
{
  if(dp[node][d]!=-1)return dp[node][d];
  int now=0;
  if(!d)
  {
    for(auto x:adj[node])
      if(x!=par)now+=dfs(x,node,k);
    now+=aa[node];
  }
  int id=0;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    id++;
    for(int i=0;i<=k;i++)
      rm[id][i]=dfs(x,node,i);
  }
  for(int i=1;i<=id;i++)
  {
    for(int j=0;j<=k;j++)
      qm[i][j]=qm[i-1][j]+rm[i][j];
  }
  for(int i=1;i<=id;i++)
  {
    for(int j=k;j>=max(d-1,0);j--)
    {
      int l=max(0,max(d-1,k-1-j));
      now=max(now,rm[i][j]+qm[id][l]-rm[i][l]);
    }
  }
  return dp[node][d]=now;
}
int main()
{
  dont compile
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
   for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,0,0)<<endl;
    return 0;
}