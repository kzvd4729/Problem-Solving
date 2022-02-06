/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/01/2020 19:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1320/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],id[N+2];
long dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   long ans=0;
  for(int i=n;i>=1;i--)
  {
   int x=aa[i]+(n-i);
   dp[i]=aa[i];if(id[x])dp[i]+=dp[id[x]];
   id[x]=i;ans=max(ans,dp[i]);
  }
  cout<<ans<<endl;
  return 0;
}