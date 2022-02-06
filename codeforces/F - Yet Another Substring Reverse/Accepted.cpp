/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/07/2019 21:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 9900 KB                              
*  problem: https://codeforces.com/contest/1234/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
int dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int n=s.size();
  for(int i=0;i<n;i++)
  {
    int msk=0;
    for(int j=i;j<n;j++)
    {
      int c=s[j]-'a';if(msk&(1<<c))break;
      msk|=(1<<c);dp[msk]=__builtin_popcount(msk);
    }
  }
  for(int i=0;i<(1<<20);i++)
  {
    for(int j=0;j<20;j++)
      if(i&(1<<j))dp[i]=max(dp[i],dp[i^(1<<j)]);
  }
  int ans=0;
  for(int i=0;i<(1<<20);i++)
    ans=max(ans,dp[i]+dp[(1<<20)-1-i]);
  cout<<ans<<endl;
  return 0;
}