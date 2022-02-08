/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-10 17:22:11                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 92 ms                                           memory_used: 70912 KB                             
*  problem: https://atcoder.jp/contests/dp/tasks/dp_l
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e3;
int aa[N+2],n;long dp[N+2][N+2];
long dfs(int i,int j)
{
  if(i>j)return 0;
  if(dp[i][j]!=-1)return dp[i][j];
  return dp[i][j]=max(aa[i]-dfs(i+1,j),aa[j]-dfs(i,j-1));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;for(int i=1;i<=n;i++)cin>>aa[i];
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,n)<<endl;
  return 0;
}