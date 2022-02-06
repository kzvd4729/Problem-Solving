/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 248 ms                                          memory_used: 90100 KB                             
*  problem: https://codeforces.com/contest/209/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long mod=1e9+7;
int n,aa[N+2];long dp[N+2][3];
long dfs(int st,int ls)
{
  if(st>n)return (bool)ls;
  if(dp[st][ls]!=-1)return dp[st][ls];long now=0;
  now=(now+dfs(st+1,ls))%mod;
  if(ls!=aa[st])now=(now+dfs(st+1,aa[st]))%mod;
  return dp[st][ls]=now%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;for(int i=1;i<=n;i++)aa[i]=1+(i%2);
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,0)<<endl;
  return 0;
}