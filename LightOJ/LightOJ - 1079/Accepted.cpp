/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-23 16:01:14                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 240                                        memory_used (MB): 9.7                             
*  problem: https://vjudge.net/problem/LightOJ-1079
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,tc,ml[102],n;
double ct[102],tt,dp[102][10002];
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%lf",&tt);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d%lf",&ml[i],&ct[i]);
    for(int i=0;i<=100;i++)
      for(int j=0;j<=10000;j++)dp[i][j]=2.0;
    dp[0][0]=0.0;
    for(int i=1;i<=n;i++)
    {
      for(int j=0;j<=10000;j++)
        dp[i][j]=dp[i-1][j];
      for(int j=1;j<=10000;j++)
      {
        if(ml[i]>j)continue;
        if(dp[i-1][j-ml[i]]>=tt)continue;
        dp[i][j]=min(dp[i][j],dp[i-1][j-ml[i]]+((1.00-dp[i-1][j-ml[i]])*ct[i]));
      }
    }
    int print;
    for(int j=0;j<=10000;j++)
      if(dp[n][j]<tt)print=j;
    printf("Case %d: %d\n",++tc,print);
  }
  return 0;
}