/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/20/2019 15:14                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/360/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long aa[N+2],n,k;
bool intersect(long a,long b,long c,long d)
{
 if(a>c)swap(a,c),swap(b,d);
 if(b<c)return false;
 return true;
}
bool ok(long x)
{
 long cnt=0,lo=aa[1],hi=aa[1];
 for(long i=2;i<=n;i++)
 {
  long lr=aa[i]-x,rr=aa[i]+x;
  if(intersect(lr,rr,lo,hi))
   lo=aa[i],hi=aa[i];
  else cnt++,lo-=x,hi+=x;
 }
 return cnt<=k;
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 cin>>n>>k;
 for(long i=1;i<=n;i++)cin>>aa[i];
  long lo=0,hi=2e9,md;
 while(hi-lo>2)
 {
  md=(lo+hi)/2;
  if(ok(md))hi=md;
  else lo=md;
  //cout<<lo<<" "<<hi<<endl;
 }
 for(md=lo;md<=hi;md++)
  if(ok(md))cout<<md<<endl,exit(0);
 return 0;
}