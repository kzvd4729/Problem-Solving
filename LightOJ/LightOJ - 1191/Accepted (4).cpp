/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-30 16:47:00                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 24                                         memory_used (MB): 3                               
*  problem: https://vjudge.net/problem/LightOJ-1191
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,tc,dp[55][55][55],rn,n,m,k;
void make_dp(void)
{
  for(rn=1;rn<=50;rn++)
  {
    for(m=1;m<=rn;m++)dp[rn][1][m]=1;
    for(k=1;k<50;k++)
    {
      for(n=1;n<=50;n++)
      {
        for(m=1;m<=rn;m++)
        {
          if(n+m>50)continue;
          dp[rn][k+1][n+m]+=dp[rn][k][n];
        }
      }
    }
  }
}
int main()
{
  make_dp();
  scanf("%lld",&t);
  while(t--)
  {
    scanf("%lld%lld%lld",&n,&k,&m);
    printf("Case %lld: %lld\n",++tc,dp[m][k][n]);
  }
  return 0;
}