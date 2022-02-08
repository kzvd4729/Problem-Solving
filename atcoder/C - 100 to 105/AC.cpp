/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-01 18:08:48                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 2 ms                                            memory_used: 640 KB                               
*  problem: https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  dp[0]=1;
  for(int i=0;i<=n;i++)
  {
    for(int j=100;j<=105;j++)
      dp[i+j]|=dp[i];
  }
  cout<<dp[n]<<endl;
    return 0;
}