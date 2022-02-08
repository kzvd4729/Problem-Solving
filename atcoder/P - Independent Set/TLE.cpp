/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-11 09:15:13                      
*  solution_verdict: TLE                                     language: C++14 (GCC 5.4.1)                       
*  run_time: 2104 ms                                         memory_used: 12800 KB                             
*  problem: https://atcoder.jp/contests/dp/tasks/dp_p
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const long mod=1e9+7;
long dp[N+2][2];
vector<int>adj[N+2];
long dfs(int node,int par,int cl)
{
  long now=1;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(!cl)
    {
      dfs(x,node,0);dfs(x,node,1);
      now=(now*(dp[x][0]+dp[x][1]))%mod;
    }
    else
    {
      dfs(x,node,0);
      now=(now*dp[x][0])%mod;
    }
  }
  return dp[node][cl]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cout<<(dfs(1,-1,0)+dfs(1,-1,1))%mod<<endl;
  return 0;
}