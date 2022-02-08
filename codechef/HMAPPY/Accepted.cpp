/****************************************************************************************
*  @author: kzvd4729                                         created: 06-10-2018 01:26:00                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.07 sec                                        memory_used: 17.2M                                
*  problem: https://www.codechef.com/OCT18A/problems/HMAPPY
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long aa[N+2],bb[N+2],n,m;
bool is_ok(long md)
{
  long rm=m;
  for(long i=1;i<=n;i++)
  {
    long eff=md/bb[i];
    if(aa[i]>eff)
      rm-=(aa[i]-eff);
    if(rm<0)return false;
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(long i=1;i<=n;i++)
    cin>>aa[i];
  for(long i=1;i<=n;i++)
    cin>>bb[i];
  long lo=0,hi=1e18,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    is_ok(md)?hi=md:lo=md;
  }
  for(md=lo;md<=hi;md++)
  {
    if(is_ok(md))cout<<md<<endl,exit(0);
  }
  return 0;
}