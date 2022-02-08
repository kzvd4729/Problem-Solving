/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-10 17:47:49                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 98 ms                                           memory_used: 79360 KB                             
*  problem: https://atcoder.jp/contests/dp/tasks/dp_m
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const long mod=1e9+7;
long dp[102][N+2],aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=0;i<=k;i++)dp[0][i]=1;
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<=k;j++)
    {
      long sm=dp[i-1][j];
      int ii=max(j-aa[i],0LL);
      if(ii)sm=(sm-dp[i-1][ii-1]+mod)%mod;
      dp[i][j]=sm;
    }
    if(i==n)continue;
    for(int j=1;j<=k;j++)
      dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
  }
  cout<<dp[n][k]<<endl;
  return 0;
}