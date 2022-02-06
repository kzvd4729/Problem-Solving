/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/18/2018 16:17                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 600 KB                               
*  problem: https://codeforces.com/contest/1077/problem/F1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e2;
const long inf=1e13;
int aa[N+2];
long dp[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k,x;cin>>n>>k>>x;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=0;i<=N;i++)
    for(int j=0;j<=N;j++)
      dp[i][j]=-inf;
  dp[0][0]=0;
  // for(int i=1;i<=n;i++)
  // {
  //   for(int j=1;j<=x;j++)
  //   {
  //     for(int l=i-1;l>=max(0,i-k);l--)
  //     {
  //       dp[i][j]=max(dp[i][j],dp[l][j-1]+aa[i]);
  //     }
  //   }
  // }
  for(int j=1;j<=x;j++)
  {
    for(int i=1;i<=n;i++)
    {
      for(int l=i-1;l>=max(0,i-k);l--)
      {
        dp[i][j]=max(dp[i][j],dp[l][j-1]+aa[i]);
      }
    }
  }
  long mn=-inf;
  for(int i=n;i>=max(0,n-k+1);i--)
    mn=max(mn,dp[i][x]);
  if(mn<0)mn=-1;
  cout<<mn<<endl;
  return 0;
}