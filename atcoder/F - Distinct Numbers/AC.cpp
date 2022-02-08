/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-19 19:03:12                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 73 ms                                           memory_used: 12544 KB                             
*  problem: https://atcoder.jp/contests/abc143/tasks/abc143_f
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=3e5;
long aa[N+2],cnt[N+2],fr[N+2],qm[N+2],mv[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=1;i<=n;i++)
  {
    cin>>aa[i];cnt[aa[i]]++;
  }
  for(long i=1;i<=N;i++)
    if(cnt[i])fr[cnt[i]]++;
  for(long i=1;i<=N;i++)qm[i]=qm[i-1]+fr[i]*i;
  for(long i=N;i>=1;i--)fr[i]+=fr[i+1];
   for(long i=1;i<=N;i++)
    mv[i]=qm[i-1]+fr[i]*i;
   for(long i=1;i<=n;i++)
  {
    long lo=1,hi=N,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(i*md<=mv[md])lo=md;
      else hi=md;
    }
    for(md=hi;md>=lo;md--)
      if(i*md<=mv[md])break;
    cout<<md<<"\n";
  }
  return 0;
}