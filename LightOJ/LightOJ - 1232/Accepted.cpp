/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-22 19:26:07                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 328                                        memory_used (MB): 1.8                             
*  problem: https://vjudge.net/problem/LightOJ-1232
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=100000007;
int t,tc,n,arr[102],k;
long dp[10002];
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
      scanf("%d",&arr[i]);
    memset(dp,0,sizeof(dp));
    dp[0]=1LL;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=k;j++)
      {
        if(arr[i]<=j)
          dp[j]+=dp[j-arr[i]];
        dp[j]%=mod;
      }
    }
    printf("Case %d: %lld\n",++tc,dp[k]%mod);
  }
  return 0;
}