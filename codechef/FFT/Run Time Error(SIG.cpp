/****************************************************************************************
*  @author: kzvd4729                                         created: 23-04-2020 16:03:36                      
*  solution_verdict: Run Time Error(SIGABRT)                 language: C++14                                   
*  run_time: 0.06 sec                                        memory_used: 22.5M                                
*  problem: https://www.codechef.com/problems/FFT
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const int mod=998244353;
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
int fac[N+2];
void init()
{
  fac[0]=1;
  for(int i=1;i<=N;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
}
int ncr(int n,int r)
{
  int ret=(1LL*fac[n]*big(fac[r],mod-2))%mod;
  return (1LL*ret*big(fac[n-r],mod-2))%mod;
}
int cnt[N+2];
int solve(int n)
{
  for(int i=1;i<=n;i++)cnt[i]=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;if(x>n)assert(0);
    cnt[x]++;
  }
  long ans=1;
  for(int i=2;i<=n;i++)
  {
    if(cnt[i]%i)assert(0);
    while(cnt[i])
    {
      ans=(ans*ncr(cnt[i],i))%mod;
      ans=(ans*fac[i-1])%mod;
      cnt[i]-=i;
    }
  }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  init();int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;cout<<solve(n)<<"\n";
  }
  return 0;
}