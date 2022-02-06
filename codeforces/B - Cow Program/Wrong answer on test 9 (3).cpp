/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/01/2019 10:08                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 186 ms                                          memory_used: 9700 KB                              
*  problem: https://codeforces.com/contest/283/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],n;long dp[N+2][2];
int col[N+2][2];
long dfs(int x,int f)
{
  if(x<=0||x>n)return 0;
  if(col[x][f]==1)dp[x][f]=-1e18;col[x][f]=1;
  if(dp[x][f]!=-1)return dp[x][f];
  dp[x][f]=0;
  if(!f)dp[x][f]=aa[x]+dfs(x+aa[x],1);
  else dp[x][f]=aa[x]+dfs(x-aa[x],0);
  col[x][f]=2;
  return dp[x][f];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=2;i<=n;i++)
    cin>>aa[i];
  memset(dp,-1,sizeof(dp));
  for(int i=1;i<n;i++)
  {
    dp[1][0]=-1;dp[1][1]=-1;
    aa[1]=i;long ans=dfs(1,0);
    if(ans<0)ans=-1;cout<<ans<<"\n";
  }
  return 0;
}