/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/17/2020 11:22                        
*  solution_verdict: Wrong answer on test 23                 language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 31300 KB                             
*  problem: https://codeforces.com/contest/855/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long aa[N+2],dp1[N+2],dp2[N+2],dp3[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,p,q,r;cin>>n>>p>>q>>r;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=n;i++)dp1[i]=-2e9,dp2[i]=-2e9,dp3[i]=-2e9;
  for(int i=n;i>=1;i--)
  {
    dp1[i]=max(dp1[i+1],aa[i]*r);
    dp2[i]=max(dp2[i+1],aa[i]*q+dp1[i]);
    dp3[i]=max(dp3[i+1],aa[i]*p+dp2[i]);
  }
  cout<<dp3[1]<<endl;
  return 0;
}