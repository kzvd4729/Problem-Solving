/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/09/2019 20:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 11800 KB                             
*  problem: https://codeforces.com/contest/1111/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];long qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k,m;cin>>n>>k>>m;
  for(int i=1;i<=n;i++)cin>>aa[i];
  sort(aa+1,aa+n+1);
  for(int i=n;i>=1;i--)
    qm[i]=qm[i+1]+aa[i]*1LL;
  double ans=0.0;
  for(int i=0;i<n;i++)
  {
    if(m<0)continue;
    long sm=qm[i+1],rm=n-i;
    sm+=min(k*rm,m*1LL);
     double rs=(sm*1.0)/(rm*1.0);
    ans=max(ans,rs);
    m--;
  }
  cout<<setprecision(9)<<fixed<<ans<<endl;
  return 0;
}