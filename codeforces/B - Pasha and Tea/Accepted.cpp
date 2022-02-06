/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/05/2020 10:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/557/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,w;cin>>n>>w;
  for(int i=1;i<=n+n;i++)cin>>aa[i];
   sort(aa+1,aa+n+n+1);
  double a=min(aa[1]*1.0,((aa[n+1]*1.0)/2.0));
  double ans=w;
  ans=min(ans,a*(3*n));
  cout<<setprecision(9)<<fixed<<ans<<endl;
   return 0;
}