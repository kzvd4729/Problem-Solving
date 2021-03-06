/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/19/2019 20:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 311 ms                                          memory_used: 18800 KB                             
*  problem: https://codeforces.com/contest/1221/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
const long inf=2e18;
long aa[N+2],bb[N+2];
long dp[N+2][6];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i]>>bb[i];
    for(int i=0;i<=n;i++)
      for(int j=0;j<=5;j++)dp[i][j]=0;
    for(int j=0;j<=5;j++)
      dp[1][j]=bb[1]*j;
    for(int i=2;i<=n;i++)
    {
      for(int j=0;j<=5;j++)
      {
        long mn=inf;
        for(int k=0;k<=5;k++)
        {
          if(aa[i]+j==aa[i-1]+k)continue;
          mn=min(mn,dp[i-1][k]);
        }
        dp[i][j]=mn+bb[i]*j;
      }
    }
    long mn=inf;
    for(int j=0;j<=5;j++)
      mn=min(mn,dp[n][j]);
    cout<<mn<<"\n";
  }
  return 0;
}