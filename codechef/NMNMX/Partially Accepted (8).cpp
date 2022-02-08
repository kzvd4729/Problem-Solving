/****************************************************************************************
*  @author: kzvd4729                                         created: 16-07-2018 00:46:15                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 15M                                  
*  problem: https://www.codechef.com/JULY18A/problems/NMNMX
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
const long N=5e3;
long t,n,k,arr[N+2],ans;
long fac[N+2];
void factorial(void)
{
  fac[0]=1LL;
  for(long i=1;i<=N;i++)
    fac[i]=(fac[i-1]*i)%mod;
}
long bigmod(long b,long p,long mod)
{
  long ret=1LL;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;
    p/=2;
  }
  return ret%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  factorial();
  cin>>t;
  while(t--)
  {
    cin>>n>>k;
    for(long i=1;i<=n;i++)
      cin>>arr[i];
    sort(arr+1,arr+n+1);
    ans=1LL;
    for(long i=1;i<=n;i++)
    {
      long npr,ncr;
      npr=(fac[n-1]*bigmod(fac[n-1-(k-1)],mod-2,mod))%mod;
      ncr=(npr*bigmod(fac[k-1],mod-2,mod))%mod;
      long tmp=ncr;
      long sm=i-1;
      long bg=n-i;
      if(k-1<=sm)
      {
        npr=(fac[sm]*bigmod(fac[sm-(k-1)],mod-2,mod))%mod;
        ncr=(npr*bigmod(fac[k-1],mod-2,mod))%mod;
        tmp=(tmp-ncr+mod)%mod;
      }
      if(k-1<=bg)
      {
        npr=(fac[bg]*bigmod(fac[bg-(k-1)],mod-2,mod))%mod;
        ncr=(npr*bigmod(fac[k-1],mod-2,mod))%mod;
        tmp=(tmp-ncr+mod)%mod;
      }
      //cout<<tmp<<endl;
      ans=(ans*bigmod(arr[i],tmp,mod))%mod;
    }
    cout<<ans<<endl;
  }
  return 0;
}