/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-08 10:49:07                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 20                                         memory_used (MB): 2.8                             
*  problem: https://vjudge.net/problem/LightOJ-1191
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=50;
int t,tc,n,m,k,rn;
long dp[N+2][N+2][N+2];
void make_dp(void)
{
  for(rn=1;rn<=N;rn++)
  {
    for(m=1;m<=rn;m++)dp[rn][1][m]=1LL;
    for(k=1;k<N;k++)
    {
      for(n=1;n<=N;n++)
      {
        for(m=1;m<=rn;m++)
        {
          if(n+m>N)continue;
          dp[rn][k+1][n+m]+=dp[rn][k][n];
        }
      }
    }
  }
}
int main()
{
  make_dp();
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d%d",&n,&k,&m);
    printf("Case %d: %lld\n",++tc,dp[m][k][n]);
  }
  return 0;
}