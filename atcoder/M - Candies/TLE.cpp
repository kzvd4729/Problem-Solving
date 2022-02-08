/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-10 17:36:37                      
*  solution_verdict: TLE                                     language: C++14 (GCC 5.4.1)                       
*  run_time: 2104 ms                                         memory_used: 80000 KB                             
*  problem: https://atcoder.jp/contests/dp/tasks/dp_m
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const long mod=1e9+7;
long n,dp[102][N+2],aa[N+2];
long dfs(int st,int k)
{
  if(st>n)return !k;
  if(dp[st][k]!=-1)return dp[st][k];
  long now=0;
  for(int i=0;i<=min(aa[st],k*1LL);i++)
    now=(now+dfs(st+1,k-i))%mod;
  return dp[st][k]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int k;cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,k)<<endl;
  return 0;
}