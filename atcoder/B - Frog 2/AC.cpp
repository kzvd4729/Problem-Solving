/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-10 16:27:51                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 35 ms                                           memory_used: 1024 KB                              
*  problem: https://atcoder.jp/contests/dp/tasks/dp_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2],dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=2;i<=n;i++)
  {
    dp[i]=2e9;
    for(int j=1;j<=k;j++)
    {
      if(i-j<=0)continue;
      dp[i]=min(dp[i],dp[i-j]+abs(aa[i]-aa[i-j]));
    }
  }
  cout<<dp[n]<<endl;
  return 0;
}