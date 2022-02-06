/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/21/2019 00:22                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 655 ms                                          memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1254/problem/B2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6+10;
const long inf=1e18;
long aa[N+2],bb[N+2],n;
bool isPrime(long x)
{
  if(x==1)return 0;
  long sq=sqrt(x+1);
  for(long i=2;i<=sq;i++)
    if(x%i==0)return 0;
  return 1;
}
long cal(long p)
{
  long now=0;
  for(long i=1;i<=n;i++)aa[i]=bb[i];
  for(long i=1;i<=n;i++)
  {
    if(aa[i]<0)
    {
      now-=aa[i];aa[i+1]+=aa[i];
    }
    else
    {
      long ex=aa[i]%p;
      if(ex<p-ex)now+=ex,aa[i+1]+=ex;
      else now+=p-ex,aa[i+1]-=(p-ex);
    }
  }
  return now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;long sm=0;
  for(long i=1;i<=n;i++)cin>>aa[i],sm+=aa[i];
  for(long i=1;i<=n;i++)bb[i]=aa[i];
   long ans=inf;long sq=sqrt(sm+1);
  for(long p=1;p<=sq;p++)
  {
    if(sm%p)continue;
    if(isPrime(p))ans=min(ans,cal(p));
    if(isPrime(sm/p))ans=min(ans,cal(sm/p));
  }
  if(ans==inf)ans=-1;
  cout<<ans<<endl;
  return 0;
}