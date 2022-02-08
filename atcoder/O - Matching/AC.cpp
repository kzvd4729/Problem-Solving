/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-11 09:01:21                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 367 ms                                          memory_used: 172288 KB                            
*  problem: https://atcoder.jp/contests/dp/tasks/dp_o
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long mod=1e9+7;
int n,mt[21][21],dp[21][(1<<21)];
long dfs(int st,int msk)
{
  if(st==n)return 1;
  if(dp[st][msk]!=-1)return dp[st][msk];
  long now=0;
  for(int i=0;i<n;i++)
  {
    if(msk&(1<<i)||!mt[st][i])continue;
    now=(now+dfs(st+1,msk|(1<<i)))%mod;
  }
  return dp[st][msk]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>mt[i][j];
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,0)<<endl;
  return 0;
}