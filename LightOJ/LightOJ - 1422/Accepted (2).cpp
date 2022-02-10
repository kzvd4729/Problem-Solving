/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-01 02:39:19                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 124                                        memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1422
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e8;
int t,tc,n,arr[102],dp[102][102];
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d",&arr[i]);
    for(int i=1;i<=100;i++)
      for(int j=1;j<=100;j++)
      {
        if(i==j)dp[i][j]=1;
        else if(i<j)dp[i][j]=inf;
        else dp[i][j]=0;
      }
    for(int len=2;len<=n;len++)
      for(int l=1;l<=n-len+1;l++)
        for(int i=l+1;i<=l+len-1;i++)
        {
          dp[l][l+len-1]=min(dp[l][l+len-1],dp[l][i-1]+dp[i][l+len-1]);
          if(arr[l]==arr[i])dp[l][l+len-1]=min(dp[l][l+len-1],dp[l][i-1]+dp[i+1][l+len-1]);
        }

    printf("Case %d: %d\n",++tc,dp[1][n]);
  }
  return 0;
}