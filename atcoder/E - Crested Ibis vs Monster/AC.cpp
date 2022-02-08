/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-26 18:14:36                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 128 ms                                          memory_used: 43776 KB                             
*  problem: https://atcoder.jp/contests/abc153/tasks/abc153_e
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],bb[N+2],dp[10000+2][1000+2];
int dfs(int h,int n)
{
  if(h<=0)return 0;if(n<1)return inf;
  if(dp[h][n]!=-1)return dp[h][n];
  return dp[h][n]=min(bb[n]+dfs(h-aa[n],n),dfs(h,n-1));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int h,n;cin>>h>>n;
  for(int i=1;i<=n;i++)cin>>aa[i]>>bb[i];
  memset(dp,-1,sizeof(dp));cout<<dfs(h,n)<<endl;
  return 0;
}