/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/19/2019 21:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1141/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long inf=1e18;
long aa[N+2],tot;
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 long h,n;cin>>h>>n;
 for(long i=1;i<=n;i++)cin>>aa[i],tot+=aa[i];
 long ans=inf,qm=0;
 for(long i=1;i<=n;i++)
 {
  qm+=aa[i];long th=h+qm;
  if(th<=0)ans=min(ans,i);
  else
  {
   if(tot>=0)continue;long tt=-tot;
   ans=min(ans,i+n*((long)((th+tt-1)/tt)));
  }
 }
 if(ans==inf)ans=-1;
 cout<<ans<<endl;
 return 0;
}