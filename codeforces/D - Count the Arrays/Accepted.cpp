/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/09/2020 22:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1312/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
 const int mod=998244353;
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
  if(r>n)return 0;
  int a=fac[n];a=(1LL*a*big(fac[r],mod-2))%mod;
  return (1LL*a*big(fac[n-r],mod-2))%mod;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  init(N);
   int n,m;cin>>n>>m;long ans=0;
   long now=0;
  for(int j=m;j>=n-1;j--)
  {
   if(j-n+1<0)continue;
   now=(now+1LL*fac[j-1]*big(fac[j-n+1],mod-2))%mod;
  }
  for(int i=1;i<=n;i++)
  {
   if(n-i-1<0)continue;
    ans=(ans+1LL*big(fac[i-1],mod-2)*big(fac[n-i-1],mod-2)%mod*now%mod*(i-1))%mod;
  }
  cout<<ans<<endl;
  return 0;
}