/****************************************************************************************
*  @author: kzvd4729                                         created: May/07/2019 20:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/256/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long n,x,y,c;
long cal(long md)
{
  long tt=md*md+(md+1)*(md+1),ds,rm;
   rm=md-(n-y);
  if(rm>0)tt-=rm*rm;
   rm=md-(n-x);
  if(rm>0)tt-=rm*rm;
   rm=md-(y-1);
  if(rm>0)tt-=rm*rm;
   rm=md-(x-1);
  if(rm>0)tt-=rm*rm;
    ds=(x-0)+(n+1-y);rm=md-ds+1;
  if(rm>0)tt+=(rm*(rm+1))/2;
   ds=(x-0)+(y-0);rm=md-ds+1;
  if(rm>0)tt+=(rm*(rm+1))/2;
   ds=(n+1-x)+(n+1-y);rm=md-ds+1;
  if(rm>0)tt+=(rm*(rm+1))/2;
   ds=(n+1-x)+(y-0);rm=md-ds+1;
  if(rm>0)tt+=(rm*(rm+1))/2;
   return tt;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>x>>y>>c;
  //cout<<cal(2)<<endl;
  long lo=0,hi=8e5,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(cal(md)>=c)hi=md;
    else lo=md;
  }
  for(md=lo;md<=hi;md++)
    if(cal(md)>=c)cout<<md<<endl,exit(0);
  return 0;
}