/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2019 21:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1139/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  long ans=0;aa[n+1]=2e9;
  for(int i=n;i>=1;i--)
  {
    aa[i]=min(aa[i],aa[i+1]-1);
    aa[i]=max(aa[i],0);ans+=aa[i]*1LL;
  }
  cout<<ans<<endl;
  return 0;
}