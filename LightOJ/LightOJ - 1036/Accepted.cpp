/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-01 18:04:14                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 384                                        memory_used (MB): 5.7                             
*  problem: https://vjudge.net/problem/LightOJ-1036
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int ur[505][505],rd[505][505],t,tc,n,m,dp[505][505][2],r=0,u=1;
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
      {
        scanf("%d",&ur[i][j]);
        ur[i][j]+=ur[i][j-1];
      }
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
      {
        scanf("%d",&rd[i][j]);
        rd[i][j]+=rd[i-1][j];
      }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        dp[i][j][r]=max(dp[i][j-1][r],dp[i][j-1][u])+rd[i][j];
        dp[i][j][u]=max(dp[i-1][j][u],dp[i-1][j][r])+ur[i][j];
      }
    }
    printf("Case %d: %d\n",++tc,max(dp[n][m][r],dp[n][m][u]));
  }
  return 0;
}