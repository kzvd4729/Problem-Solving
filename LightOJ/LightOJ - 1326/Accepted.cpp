/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-01 16:49:08                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 22                                         memory_used (MB): 6.2                             
*  problem: https://vjudge.net/problem/LightOJ-1326
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int mod=10056;
const int N=1e3;
int t,tc,n,ncr[N+2][N+2],dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  for(int i=1;i<=N;i++)
    ncr[i][1]=i;
  for(int i=2;i<=N;i++)
    for(int j=2;j<=N;j++)
      ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
 
  dp[1]=1;
  for(int i=2;i<=N;i++)
  {
    dp[i]=1;
    for(int j=i-1;j>=1;j--)
    {
      dp[i]=(dp[i]+ncr[i][j]*dp[i-j])%mod;
    }
  }
  cin>>t;
  while(t--)
  {
    cin>>n;
    cout<<"Case "<<++tc<<": "<<dp[n]<<endl;
  }
  return 0;
}