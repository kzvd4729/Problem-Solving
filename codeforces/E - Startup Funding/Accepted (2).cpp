/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/24/2020 21:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 810 ms                                          memory_used: 11800 KB                             
*  problem: https://codeforces.com/contest/633/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define double long double
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2],dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>aa[i],aa[i]*=100;
  for(int i=1;i<=n;i++)cin>>bb[i];
  dp[n]=min(aa[n],bb[n]);
  for(int i=n-1;i>=1;i--)
    dp[i]=max(min(aa[i],bb[i]),min(bb[i],dp[i+1]));
  sort(dp+1,dp+n+1);
  double ans=0,p=(m*1.0)/(n*1.0);
  for(int i=1;i<=n-m+1;i++)
  {
    ans+=dp[i]*p;
    p*=((n-m-i+1)*1.0)/((n-i)*1.0);
  }
  cout<<setprecision(10)<<fixed<<ans<<endl;
  return 0;
}