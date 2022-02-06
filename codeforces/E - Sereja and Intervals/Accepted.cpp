/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/03/2019 20:14                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 343 ms                                          memory_used: 109800 KB                            
*  problem: https://codeforces.com/contest/367/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6,mod=1e9+7;
int n,m,x;
vector<vector<vector<int> > >dp;
int dfs(int i,int st,int rm)
{
  if(rm<0||st>n||st<0)return 0;
  if(i>m)
  {
    if(st==0&&rm==0)return 1;
    return 0;
  }
  if(dp[i][st][rm]!=-1)return dp[i][st][rm];
  int now=0;
  if(i==x)
  {
    now=(now+dfs(i+1,st,rm-1))%mod;
    now=(now+dfs(i+1,st+1,rm-1))%mod;
    return dp[i][st][rm]=now;
  }
  now=(now+dfs(i+1,st,rm))%mod;
  now=(now+dfs(i+1,st,rm-1))%mod;
  now=(now+dfs(i+1,st+1,rm-1))%mod;
  now=(now+dfs(i+1,st-1,rm))%mod;
  return dp[i][st][rm]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>x;
  if(n>m)cout<<0<<endl,exit(0);
   dp.resize(m+1);
  for(int i=0;i<=m;i++)
  {
    dp[i].resize(n+1);
    for(int j=0;j<=n;j++)
    {
      dp[i][j].resize(n+1);
      for(int k=0;k<=n;k++)
        dp[i][j][k]=-1;
    }
  }
  int ans=dfs(1,0,n);
   for(int i=n;i>=1;i--)
    ans=(1LL*ans*i)%mod;
  cout<<ans<<endl;
   return 0;
}