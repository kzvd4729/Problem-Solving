/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/27/2019 18:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1250/problem/J
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long n,k,aa[N+2];
bool ok(long md)
{
  long cnt=0,rm=0;
  for(int i=1;i<=n;i++)
  {
    long now=rm+aa[i];long ad=now/md;
    if(ad==0)rm=aa[i];else rm=now%md;
    cnt+=ad;
  }
  return cnt>=k;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>aa[i];
    long lo=1,hi=1e18,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(ok(md))lo=md;else hi=md;
    }
    long ans=0;
    for(md=hi;md>=lo;md--)
    {
      if(ok(md))
      {
        ans=k*md;break;
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}