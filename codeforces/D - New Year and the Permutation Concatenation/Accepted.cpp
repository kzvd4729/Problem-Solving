/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/01/2019 13:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 436 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1091/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long mod=998244353;
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
void factorial(void)
{
  fac[0]=1;
  for(long i=1;i<=N;i++)
    fac[i]=(fac[i-1]*i)%mod;
}
long npr(long n,long r)
{
  long ret=fac[n];
  ret=(ret*bigmod(fac[n-r],mod-2,mod))%mod;
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long ans=0;long n;cin>>n;factorial();
  ans=fac[n];
  for(long i=1;i<=n;i++)
    ans=(ans+(npr(n,i)*((fac[n-i]-1+mod)%mod)%mod)%mod)%mod;
  cout<<ans<<endl;
  return 0;
}