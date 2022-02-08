/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-10 16:33:55                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 32 ms                                           memory_used: 11136 KB                             
*  problem: https://atcoder.jp/contests/dp/tasks/dp_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,mt[N+2][4],dp[N+2][4];
int dfs(int st,int ls)
{
  if(st>n)return 0;
  if(dp[st][ls]!=-1)return dp[st][ls];
  int now=0;
  for(int i=1;i<=3;i++)
  {
    if(i==ls)continue;
    now=max(now,mt[st][i]+dfs(st+1,i));
  }
  return dp[st][ls]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=3;j++)
      cin>>mt[i][j];
  memset(dp,-1,sizeof(dp));
  cout<<dfs(1,0)<<endl;
  return 0;
}