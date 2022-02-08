/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-12 18:35:46                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 49 ms                                           memory_used: 4736 KB                              
*  problem: https://atcoder.jp/contests/abc151/tasks/abc151_e
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int aa[N+2];
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
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
  sort(aa+1,aa+n+1,greater<int>());
   if(k==1)cout<<0<<endl,exit(0);
   // for(int i=1;i<=n;i++)cout<<aa[i]<<" ";
  //   cout<<endl;
   init(n);long ans=0;
  for(int i=1;i<=n;i++)
  {
    int rgt=n-i;
    if(rgt>=k-1)ans=(1LL*ans+1LL*ncr(rgt,k-1)*aa[i])%mod;
     int lft=i-1;
    if(lft>=k-1)ans=(1LL*ans-1LL*ncr(lft,k-1)*aa[i])%mod;
   }
  ans=(ans+mod)%mod;cout<<ans<<endl;
    return 0;
}