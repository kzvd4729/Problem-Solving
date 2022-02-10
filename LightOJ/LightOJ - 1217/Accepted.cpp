/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-29 19:32:08                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 4                                          memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1217
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e9;
int t,tc,n,arr[1003],dp[1003][2],ans;
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d",&arr[i]);
    dp[1][1]=arr[1];
    dp[1][0]=-inf;
    for(int i=2;i<n;i++)
    {
      dp[i][1]=max(dp[i-1][1],dp[i-1][0]+arr[i]);
      dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
    }
    ans=max(dp[n-1][1],dp[n-1][0]);
 
    dp[2][1]=arr[2];
    dp[2][0]=0;
    for(int i=3;i<=n;i++)
    {
      dp[i][1]=max(dp[i-1][1],dp[i-1][0]+arr[i]);
      dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
    }
    ans=max(ans,dp[n][1]);
    ans=max(ans,dp[n][0]);
    printf("Case %d: %d\n",++tc,ans);
  }
  return 0;
}