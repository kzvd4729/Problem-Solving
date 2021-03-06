/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/16/2018 21:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 31500 KB                             
*  problem: https://codeforces.com/contest/1081/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
const long mod=998244353;
long n,m,k,dp[N+2][N+2];
long dfs(long st,long kk)
{
  if(kk>k)return 0;
  if(st>n)
  {
    if(kk==k)return 1;
    else return 0;
  }
  if(dp[st][kk]!=-1)return dp[st][kk];
  long here=0;
  here=(here+dfs(st+1,kk))%mod;
  here=(here+(m-1)*dfs(st+1,kk+1))%mod;
  return dp[st][kk]=here%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>k;
  if(n==1)cout<<m%mod<<endl,exit(0);
   if(m==1&&k>1)cout<<0<<endl,exit(0);
   memset(dp,-1,sizeof(dp));
   cout<<(m*dfs(2,0))%mod<<endl;
     return 0;
}