/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/25/2019 15:29                        
*  solution_verdict: Time limit exceeded on test 5           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 35300 KB                             
*  problem: https://codeforces.com/contest/1261/problem/D1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
const int mod=998244353;
int aa[N+2],n,k,dp[2000+2][4000+2];
int dfs(int i,int bl)
{
  if(i>n)return bl>2000;
  int now=0;
  if(aa[i]==aa[i+1])
    now=(now+1LL*k*dfs(i+1,bl))%mod;
  else
  {
    now=(now+1LL*(k-2)*dfs(i+1,bl))%mod;
    now=(now+dfs(i+1,bl-1))%mod;
    now=(now+dfs(i+1,bl+1))%mod;
  }
  return dp[i][bl]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
  aa[n+1]=aa[1];
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,2000)<<endl;  
  return 0;
}