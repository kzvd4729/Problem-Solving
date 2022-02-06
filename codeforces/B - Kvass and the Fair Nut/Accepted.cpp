/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/11/2018 03:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1084/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long aa[N+2],n,s;
bool ok(long mn)
{
  long sum=0;
  for(long i=1;i<=n;i++)
  {
    if(aa[i]>mn)sum+=aa[i]-mn;
  }
  return sum>=s;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>s;long sum=0,mn=1e9;
  for(long i=1;i<=n;i++)
  {
    cin>>aa[i];sum+=aa[i];
    mn=min(mn,aa[i]);
  }
  if(sum<s)cout<<-1<<endl,exit(0);
   long lo=0,hi=mn,md;
  while(hi-lo>2)
  {
    md=(hi+lo)/2;
    if(ok(md))lo=md;
    else hi=md;
  }
  for(md=hi;md>=lo;md--)
    if(ok(md))cout<<md<<endl,exit(0);
  return 0;
}