/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/16/2018 19:37                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 514 ms                                          memory_used: 41200 KB                             
*  problem: https://codeforces.com/contest/11/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=22;
int n,dp[(1<<19)+2][20];
vector<int>adj[N+2];
int dfs(int st,int node,int par,int msk)
{
  int here=0;
  if(dp[msk][node]!=-1)return dp[msk][node];
  for(auto x:adj[node])
  {
    if(x==par)continue;
    else if(x==st)here++;
    else if(msk&(1<<x))continue;
    else here+=dfs(st,x,node,msk|(1<<x));
  }
  return dp[msk][node]=here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int m;cin>>n>>m;
  while(m--)
  {
    int u,v;cin>>u>>v;u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int msk=0,ans=0;
  for(int i=0;i<n;i++)
  {
    memset(dp,-1,sizeof(dp));
    msk|=(1<<i);ans+=dfs(i,i,-1,msk);
  }
  cout<<ans/2<<endl;
  return 0;
}