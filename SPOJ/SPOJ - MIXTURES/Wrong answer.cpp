/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-22 22:19:01                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-MIXTURES
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=1e12;
long dp[102][102],x,n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for(int i=0;i<=100;i++)
  {
    for(int j=0;j<=100;j++)dp[i][j]=inf;
  }
  cin>>n;
  for(int i=1;i<=n;i++)cin>>x,dp[1][x]=0;
  for(int i=2;i<=n;i++)
  {
    for(int j=0;j<100;j++)
    {
      if(dp[i-1][j]==inf)continue;
      for(int k=0;k<100;k++)
      {
        if(dp[i-1][k]==inf)continue;
        x=(j+k)%100;
        dp[i][x]=min(dp[i][x],j*k+dp[i-1][j]+dp[i-1][k]);
      }
    }
  }
  long mn=inf;
  for(int i=0;i<100;i++)mn=min(mn,dp[n][i]);
  cout<<mn<<endl;
  return 0;
}