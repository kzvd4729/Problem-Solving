/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-19 18:56:10                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1025
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,tc,dp[61][61],len;
char s[61];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  scanf("%lld",&t);
  while(t--)
  {
    scanf("%s",s);
    len=strlen(s);
    memset(dp,0,sizeof(dp));
    for(long l=1;l<=len;l++)
    {
      for(long i=1;i<=len-l+1;i++)
      {
        if(s[i-1]==s[i+l-1-1])
        {
          dp[i][i+l-1]=1;
          dp[i][i+l-1]=dp[i][i+l-1]+dp[i][i+l-1-1]+dp[i+1][i+l-1];
        }
        else dp[i][i+l-1]=dp[i][i+l-1]+dp[i][i+l-1-1]+dp[i+1][i+l-1]-dp[i+1][i+l-1-1];
      }
    }
    printf("Case %lld: %lld\n",++tc,dp[1][len]);
  }
  return 0;
}