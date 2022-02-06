/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/13/2018 17:01                        
*  solution_verdict: Memory limit exceeded on test 1         language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/543/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=5e2;
long mod,dp[N+2][N+2][N+2];
int n,m,b,arr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m>>b>>mod;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  dp[0][0][0]=1;
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<=b;j++)
    {
      for(int k=0;k<=m;k++)
      {
        dp[i][j][k]=dp[i-1][j][k];
        if(j-arr[i]>=0)dp[i][j][k]=(dp[i][j][k]+dp[i][j-arr[i]][k-1])%mod;
      }
    }
  }
  long ans=0;
  for(int i=0;i<=b;i++)
    ans=(ans+dp[n][i][m])%mod;
  cout<<ans<<endl;
  return 0;
}