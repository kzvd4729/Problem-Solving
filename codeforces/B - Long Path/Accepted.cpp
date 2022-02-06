/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/13/2019 18:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/407/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const int mod=1000000007;
int aa[N+2],dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
   for(int i=1;i<=n;i++)
  {
    dp[i]=2;
    for(int j=aa[i];j<i;j++)
    {
      dp[i]=(dp[i]+dp[j])%mod;
    }
  }
  for(int i=1;i<=n;i++)
    dp[i]=(dp[i-1]+dp[i])%mod;
  cout<<dp[n]<<endl;
  return 0;
}