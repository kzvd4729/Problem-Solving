/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-19 18:57:23                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1025
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,tc,len;
long dp[62][62];
char s[62];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  scanf("%d",&t);
  while(t--)
  {
    scanf("%s",s);
    len=strlen(s);
    memset(dp,0,sizeof(dp));
    for(int l=1;l<=len;l++)
    {
      for(int i=1;i<=len-l+1;i++)
      {
        if(s[i-1]==s[i+l-1-1])
        {
          dp[i][i+l-1]=1;
          dp[i][i+l-1]=dp[i][i+l-1]+dp[i][i+l-1-1]+dp[i+1][i+l-1];
        }
        else dp[i][i+l-1]=dp[i][i+l-1]+dp[i][i+l-1-1]+dp[i+1][i+l-1]-dp[i+1][i+l-1-1];
      }
    }
    printf("Case %d: %lld\n",++tc,dp[1][len]);
  }
  return 0;
}