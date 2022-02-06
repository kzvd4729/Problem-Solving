/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/08/2019 18:54                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 39100 KB                             
*  problem: https://codeforces.com/contest/710/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e7;
int dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,x,y;cin>>n>>x>>y;
  for(int i=1;i<=n;i++)
  {
    dp[i]=dp[i-1]+x;
    if(i%2==0)dp[i]=min(dp[i],dp[i/2]+y);
  }
  cout<<dp[n]<<endl;
  return 0;
}