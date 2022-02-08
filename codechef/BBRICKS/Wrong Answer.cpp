/****************************************************************************************
*  @author: kzvd4729                                         created: 08-10-2018 23:09:34                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 22.5M                                
*  problem: https://www.codechef.com/OCT18A/problems/BBRICKS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
const long mod=1e9+7;
long fac[N+2];
long bigmod(long b,long p,long mod)
{
  long ret=1LL;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
long ncr(long nn,long rr)
{
  long ret=fac[nn];
  ret=(ret*bigmod(fac[rr],mod-2,mod))%mod;
  ret=(ret*bigmod(fac[nn-rr],mod-2,mod))%mod;
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  fac[0]=1LL;
  for(long i=1;i<=N;i++)fac[i]=(fac[i-1]*i)%mod;
  long t;cin>>t;
  while(t--)
  {
    long n,r;cin>>n>>r;long sum=0;n=n-r+1;
    for(long k=1;k<=min(n,r);k++)
    {
      long nw=(ncr(r-1,k-1)*ncr(n,k))%mod;
      nw=(nw*bigmod(2,k,mod))%mod;
      sum+=nw;
    }
    cout<<sum<<endl;
  }
  return 0;
}