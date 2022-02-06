/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/08/2019 18:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 78300 KB                             
*  problem: https://codeforces.com/contest/710/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e7;
long dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,x,y;cin>>n>>x>>y;
  for(int i=1;i<=n;i++)
  {
    dp[i]=dp[i-1]+x;
    if(i%2==0)dp[i]=min(dp[i],dp[i/2]+y);
    else dp[i]=min(dp[i],dp[i/2+1]+y+x);
  }
  cout<<dp[n]<<endl;
  return 0;
}