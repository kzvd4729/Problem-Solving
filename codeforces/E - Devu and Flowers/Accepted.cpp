/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/18/2020 10:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 358 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/451/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=20,mod=1e9+7;
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
int fac[N+2],inv[N+2];
int init(void)
{
  fac[0]=1;
  for(int i=1;i<=N;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
  for(int i=0;i<=N;i++)inv[i]=big(fac[i],mod-2);
}
int make(long n,int k)
{
  if(n<0)return 0;int ret=1;
  for(long i=n+1;i<=n+k-1;i++)
    ret=(1LL*ret*(i%mod))%mod;
  ret=(1LL*ret*inv[k-1])%mod;
  return ret;
}
long f[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  init();int n;long s;cin>>n>>s;
  for(int i=0;i<n;i++)cin>>f[i];
   long ans=0;
  for(int msk=0;msk<(1<<n);msk++)
  {
    long tt=s;
    for(int i=0;i<n;i++)if(msk&(1<<i))tt-=(f[i]+1);
     (__builtin_popcount(msk))%2==0?ans=(ans+make(tt,n))%mod:ans=(ans-make(tt,n)+mod)%mod;
  }
  cout<<ans<<endl;
  return 0;
}