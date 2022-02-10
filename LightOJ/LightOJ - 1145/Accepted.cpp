/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-04 19:12:43                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 296                                        memory_used (MB): 2                               
*  problem: https://vjudge.net/problem/LightOJ-1145
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=100000007;
long t,n,k,s,dp[3][15005],sum,tc;
int main()
{
  scanf("%lld",&t);
  while(t--)
  {
    scanf("%lld%lld%lld",&n,&k,&s);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=k;i++)dp[1][i]=1;
    for(int i=2;i<=n;i++)
    {
      sum=0;
      for(int j=1;j<=s;j++)
      {
        dp[i%2][j]=sum;
        sum=(sum+dp[(i-1)%2][j])%mod;
        if(j>k)sum=(sum-dp[(i-1)%2][j-k]+mod)%mod;
      }
    }
    printf("Case %lld: %lld\n",++tc,dp[n%2][s]);
  }
  return 0;
}