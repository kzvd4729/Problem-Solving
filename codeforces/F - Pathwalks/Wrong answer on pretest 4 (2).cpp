/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/07/2018 23:58                        
*  solution_verdict: Wrong answer on pretest 4               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 4800 KB                              
*  problem: https://codeforces.com/contest/960/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int dp[100005],n,m,u,v,w,print;
vector<pair<int,pair<int,int> > >adj[100005];
int dfs(int node,int weight,int i)
{
  if(dp[node]!=-1)return dp[node];
  int xx=0;
  for(auto x:adj[node])
  {
    if(x.second.first>i&&x.second.second>weight)
    {
      xx=max(xx,1+dfs(x.first,x.second.second,x.second.first));
    }
  }
  return dp[node]=max(xx,dp[node]);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   memset(dp,-1,sizeof(dp));
   cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>u>>v>>w;
    adj[u].push_back({v,{i,w}});
  }
  for(int i=1;i<=n;i++)dfs(i,-1,-1);
  for(int i=1;i<=n;i++)print=max(print,dp[i]);
  cout<<print<<endl;
  return 0;
}