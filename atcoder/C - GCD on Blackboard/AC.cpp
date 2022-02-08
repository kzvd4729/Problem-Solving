/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-08 22:42:36                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 13 ms                                           memory_used: 1408 KB                              
*  problem: https://atcoder.jp/contests/abc125/tasks/abc125_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2],bb[N+2],cc[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=n;i++)
    bb[i]=__gcd(aa[i],bb[i-1]);
  for(int i=n;i>=1;i--)
    cc[i]=__gcd(aa[i],cc[i+1]);
  int ans=max(bb[n],cc[1]);
  for(int i=1;i<=n;i++)
    ans=max(ans,__gcd(bb[i-1],cc[i+1]));
  cout<<ans<<endl;
  return 0;
}