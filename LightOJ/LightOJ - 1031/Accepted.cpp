/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-01 14:29:15                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 20                                         memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1031
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e9;
int t,tc,n,arr[102],dp[102][102];
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
      {
        if(i==j)dp[i][j]=arr[i];
        else if(j>i)dp[i][j]=-inf;
        else dp[i][j]=0;
      }
    for(int len=2;len<=n;len++)
    {
      for(int l=1;l<=n-len+1;l++)
      {
        int x=0;
        for(int i=l;i<=l+len-1;i++)
        {
          x+=arr[i];
          dp[l][l+len-1]=max(dp[l][l+len-1],x-dp[i+1][l+len-1]);
        }
        x=0;
        for(int i=l+len-1;i>=l;i--)
        {
          x+=arr[i];
          dp[l][l+len-1]=max(dp[l][l+len-1],x-dp[l][i-1]);
        }
      }
    }
    printf("Case %d: %d\n",++tc,dp[1][n]);
  }
  return 0;
}