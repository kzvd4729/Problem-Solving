/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/17/2019 21:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 39100 KB                             
*  problem: https://codeforces.com/contest/1195/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long aa[N+2],bb[N+2],dp[N+2][3];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=1;i<=n;i++)cin>>aa[i];
  for(long i=1;i<=n;i++)cin>>bb[i];
  for(long i=1;i<=n;i++)
  {
    dp[i][1]=max(dp[i-1][1],dp[i-1][2]+aa[i]);
    dp[i][2]=max(dp[i-1][2],dp[i-1][1]+bb[i]); 
  }
  cout<<max(dp[n][1],dp[n][2])<<endl;
  return 0;
}