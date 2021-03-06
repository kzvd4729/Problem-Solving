/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/19/2020 21:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 498 ms                                          memory_used: 106300 KB                            
*  problem: https://codeforces.com/contest/1292/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e3,inf=1e9;
vector<int>adj[N+2];
vector<pair<int,int> >ed;
int sub[N+2][N+2];long dp[N+2][N+2];
int dfs(int node,int par)
{
  if(sub[node][par])return sub[node][par];
  sub[node][par]=1;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    sub[node][par]+=dfs(x,node);
  }
  return sub[node][par];
}
long dfs(int n1,int p1,int n2,int p2)
{
  if(dp[n1][n2]!=-1)return dp[n1][n2];
  long ret=0;
  for(auto x:adj[n1])
  {
    if(x==p1)continue;
    ret=max(ret,dfs(x,n1,n2,p2));
  }
  for(auto x:adj[n2])
  {
    if(x==p2)continue;
    ret=max(ret,dfs(n1,p1,x,n2));
  }
  return dp[n1][n2]=ret+1LL*sub[n1][p1]*sub[n2][p2];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;ed.push_back({u,v});
    adj[u].push_back(v);adj[v].push_back(u);
  }
  for(int i=1;i<=n;i++)dfs(i,0);
  memset(dp,-1,sizeof(dp));
  long mx=0;
  for(auto x:ed)
    mx=max(mx,dfs(x.first,x.second,x.second,x.first));
  cout<<mx<<endl;
   return 0;
}