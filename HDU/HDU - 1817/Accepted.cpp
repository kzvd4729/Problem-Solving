/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-06 16:32:16                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 15                                         memory_used (MB): 1.4                             
*  problem: https://vjudge.net/problem/HDU-1817
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;

long big(long b,long p)
{
  long ret=1;
  while(p)
  {
    if(p&1)ret=(1LL*ret*b);
    b=(1LL*b*b);p/=2;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;
  while(cin>>n)
  {
    if(n==-1)break;long k=3;
    if(n==0)
    {
      cout<<0<<"\n";continue;
    }
    long ans=0;
    for(long i=0;i<n;i++)
      ans=(ans+big(k,__gcd(i,n)));

    if(n%2==0)
    {
      ans=(1LL*ans+(n/2)*big(k,n/2));
      ans=(1LL*ans+(n/2)*big(k,n/2+1));
      cout<<ans/(n+n)<<"\n";
    }
    else
    {
      ans=(ans+n*big(k,n/2+1));
      cout<<ans/(n+n)<<"\n";
    }
  }
  return 0;
}