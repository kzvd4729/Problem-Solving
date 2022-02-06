/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/06/2019 18:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 498 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/752/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,k,aa[N+2],md;
int cal(int x)
{
  int d=x/md;if(!d)return d;
  if(__builtin_popcount(d)==1)return d;
  int dg=32-__builtin_clz(d);
  int dd=(1<<dg);
  return max(dd/2,dd-(dd*md-x));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
  int lo=1,hi=1e7;
  while(hi-lo>2)
  {
    long cnt=0;md=(lo+hi)/2;
    for(int i=1;i<=n;i++)
      cnt+=cal(aa[i])*1LL;
    if(cnt>=k)lo=md;
    else hi=md;
  }
  for(md=hi;md>=lo;md--)
  {
    long cnt=0;
    for(int i=1;i<=n;i++)
      cnt+=cal(aa[i])*1LL;
    if(cnt>=k)cout<<md<<endl,exit(0);
  }
  cout<<-1<<endl;
  return 0;
}