/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-20 18:23:45                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 20 ms                                           memory_used: 1792 KB                              
*  problem: https://atcoder.jp/contests/agc024/tasks/agc024_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int arr[N+2],dp[N+2],pos[N+2],mx,n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  memset(dp,0,sizeof(dp));
  for(int i=1;i<=n;i++)
    dp[arr[i]]=dp[arr[i]-1]+1;
  for(int i=1;i<=n;i++)mx=max(mx,dp[i]);
  memset(dp,0,sizeof(dp));
  for(int i=n;i>=1;i--)
    dp[arr[i]]=dp[arr[i]+1]+1;
  for(int i=1;i<=n;i++)mx=max(mx,dp[i]);
  cout<<n-mx<<endl;
  return 0;
}