/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-10 16:23:44                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 9 ms                                            memory_used: 1024 KB                              
*  problem: https://atcoder.jp/contests/dp/tasks/dp_a
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
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  dp[2]=abs(aa[2]-aa[1]);
  for(int i=3;i<=n;i++)
  {
    dp[i]=dp[i-1]+abs(aa[i]-aa[i-1]);
    dp[i]=min(dp[i],dp[i-2]+abs(aa[i]-aa[i-2]));
  }
  cout<<dp[n]<<endl;
  return 0;
}