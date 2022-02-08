/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-09 18:37:46                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 655 ms                                          memory_used: 15872 KB                             
*  problem: https://atcoder.jp/contests/abc154/tasks/abc154_f
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e6,mod=1e9+7;
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
  init(N);
   int r1,c1,r2,c2;cin>>r1>>c1>>r2>>c2;
   int ans=0;
  for(int c=c1;c<=c2;c++)
  {
    ans=(ans+ncr(r2+c+1,r2))%mod;
    ans=((ans-ncr(r1+c,r1-1))%mod+mod)%mod;
  }
  cout<<ans<<endl;
    return 0;
}