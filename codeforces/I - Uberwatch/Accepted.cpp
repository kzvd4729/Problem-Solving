/****************************************************************************************
*  @author: kzvd4729#                                        created: Feb/05/2020 15:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/gym/101873/problem/I
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=m+1;i<=n;i++)
  {
    dp[i]=max(dp[i-1],aa[i]+dp[i-m]);
  }
  // for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
  //   cout<<endl;
  cout<<dp[n]<<endl;
  return 0;
}