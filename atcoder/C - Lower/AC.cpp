/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-09-01 18:20:24                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 12 ms                                           memory_used: 4736 KB                              
*  problem: https://atcoder.jp/contests/abc139/tasks/abc139_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  dp[1]=1;int mx=1;
  for(int i=2;i<=n;i++)
  {
    if(aa[i]>aa[i-1])dp[i]=1;
    else dp[i]=dp[i-1]+1;
     mx=max(mx,dp[i]);
  }
  cout<<mx-1<<endl;
  return 0;
}