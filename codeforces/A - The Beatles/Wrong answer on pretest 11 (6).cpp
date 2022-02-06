/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/31/2019 00:19                        
*  solution_verdict: Wrong answer on pretest 11              language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1142/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
vector<long>v;
void divisors(long x)
{
  long sq=sqrt(x+1);
   for(long i=1;i<=sq;i++)
  {
    if(x%i==0)
    {
      v.push_back(i);
      v.push_back(x/i);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,k;cin>>n>>k;
  divisors(n*k);long a,b;cin>>a>>b;
   long ps=1+a,f=0;
  long mn=1e18,mx=0;
  for(auto x:v)
  {
    long nx=x+ps;
     //if(nx>n*k)nx-=n*k;
     long lo=0,hi=n+n+n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(md*k+1>nx)hi=md;
      else lo=md;
    }
    for(md=hi;md>=lo;md--)
      if(md*k+1<=nx)break;
     long xx=min(nx-(md*k+1),(md+1)*k+1-nx);
    if(xx<0)assert(0);
    if(xx==b)
    {
      f=1;
      mx=max(mx,n*k/x);
      mn=min(mn,n*k/x);
    }
  }
  ps=1+k-a;
  for(auto x:v)
  {
    long nx=x+ps;
     //if(nx>n*k)nx-=n*k;
     long lo=0,hi=n+n+n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(md*k+1>nx)hi=md;
      else lo=md;
    }
    for(md=hi;md>=lo;md--)
      if(md*k+1<=nx)break;
     long xx=min(nx-(md*k+1),(md+1)*k+1-nx);
    if(xx<0)assert(0);
    if(xx==b)
    {
      f=1;
      mx=max(mx,n*k/x);
      mn=min(mn,n*k/x);
    }
  }
  if(!f)mn=n*k,mx=n*k;
  cout<<mn<<" "<<mx<<endl;
  return 0;
}