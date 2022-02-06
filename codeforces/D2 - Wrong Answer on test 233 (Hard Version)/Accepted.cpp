/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/26/2019 02:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 561 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1261/problem/D2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=998244353;
 int big(int b,int p,int m=mod)
{
  int ret=1;
  while(p){if(p&1)ret=(1LL*ret*b)%m;b=(1LL*b*b)%m;p/=2;}
  return ret;
}
int fac[N+2];
void init(int n)
{
  fac[0]=1;
  for(int i=1;i<=n;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
}
int ncr(int n,int r)
{
  int a=fac[n];a=(1LL*a*big(fac[r],mod-2))%mod;
  return (1LL*a*big(fac[n-r],mod-2))%mod;
}
int npr(int n,int r)
{
  return (1LL*fac[n]*big(fac[n-r],mod-2))%mod;
}
int ret(int n)
{
  long ok=big(2,n-1);
  ok=(ok-((1+big(-1,n))*1LL*big(4,mod-2))*ncr(n,n/2))%mod;
  return (ok+mod)%mod;
}
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;init(n);int ans=0,sm=0;
  for(int i=1;i<=n;i++)cin>>aa[i];aa[n+1]=aa[1];
  for(int i=1;i<=n;i++)if(aa[i]==aa[i+1])sm++;
  n-=sm;
  for(int i=1;i<=n;i++)
  {
    int ad=(1LL*ncr(n,i)*ret(i))%mod;
    ad=(1LL*ad*big(k-2,n-i))%mod;
    ans=(ans+ad)%mod;
  }
  cout<<(1LL*ans*big(k,sm))%mod<<endl;
  return 0;
}