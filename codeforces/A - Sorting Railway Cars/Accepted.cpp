/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/15/2018 23:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/605/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2],dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   int mx=0;
  for(int i=1;i<=n;i++)
  {
    dp[aa[i]]=dp[aa[i]-1]+1;
    mx=max(mx,dp[aa[i]]);
  }
  cout<<n-mx<<endl;
  return 0;
}