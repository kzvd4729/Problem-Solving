/****************************************************************************************
*  @author: kzvd4729                                         created: 08-10-2018 21:29:07                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.01 sec                                        memory_used: 22.5M                                
*  problem: https://www.codechef.com/OCT18A/problems/BBRICKS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e3;
const long mod=1e9+7;
long dp[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long n,k;cin>>n>>k;
    for(long i=0;i<=n;i++)dp[i][0]=1;
    for(long i=1;i<=n;i++)
    {
      for(long j=1;j<=k;j++)
      {
        if(i==1&&j==1)dp[i][j]=2;
        else
        {
          dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
          if(i>1)dp[i][j]=(dp[i][j]+dp[i-2][j-1])%mod;
        }
        //cout<<setw(5)<<dp[i][j];
      }
      //cout<<endl;
    }
    cout<<dp[n][k]<<endl;
  }
  return 0;
}