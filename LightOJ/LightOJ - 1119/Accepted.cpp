/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-07 21:38:03                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 192                                        memory_used (MB): 3.7                             
*  problem: https://vjudge.net/problem/LightOJ-1119
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int N,t,tc,n,mat[15][15],pre[15][1<<15],dp[1<<15];
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    N=(1<<n);
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        scanf("%d",&mat[i][j]);
    for(int id=0;id<n;id++)
    {
      for(int i=1;i<N;i++)
      {
        int sz=32-__builtin_clz(i)-1;
        int tmp=(1<<sz)-1;
        int msk=i&tmp;
        pre[id][i]=pre[id][msk]+mat[id][sz];
        dp[i]=1e9;
      }
    }
    for(int j=0;j<n;j++)
      dp[1<<j]=mat[j][j];
    for(int i=1;i<N;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(i&(1<<j))continue;
        int msk=i|(1<<j);
        dp[msk]=min(dp[msk],dp[i]+pre[j][i]+mat[j][j]);
      }
    }
    printf("Case %d: %d\n",++tc,dp[N-1]);
  }
  return 0;
}