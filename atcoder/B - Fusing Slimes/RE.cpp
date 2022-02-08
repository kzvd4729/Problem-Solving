/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-11 19:03:22                      
*  solution_verdict: RE                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 913 ms                                          memory_used: 41856 KB                             
*  problem: https://atcoder.jp/contests/dwacon6th-prelims/tasks/dwacon6th_prelims_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
const long mod=1e9+7;
long mt[2003][2003];
long big(long b,long p,long m=mod)
{
  long ret=1;
  while(p){if(p&1)ret=(1LL*ret*b)%m;b=(1LL*b*b)%m;p/=2;}
  return ret*1LL;
}
long fac[N+2],aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  fac[0]=1;
  for(long i=1;i<=N;i++)fac[i]=(fac[i-1]*i)%mod;
   long n;cin>>n;
  for(long i=1;i<=n;i++)cin>>aa[i];
   long ans=0;
  for(long i=2;i<n;i++)
  {
    long inv=(1LL*i*(i-1))%mod;
    inv=big(inv,mod-2);mt[1][i]=(fac[n-1]*inv)%mod;
    //cout<<mt[1][i]<<" ";
    ans=(ans+(aa[i]-aa[1])*mt[1][i])%mod;
  }
  mt[1][n]=fac[n-2];
  //cout<<fac[n-2]<<endl;
  ans=(ans+(aa[n]-aa[1])*mt[1][n])%mod;
  for(long i=2;i<n;i++)
  {
    for(long j=i+1;j<n;j++)
    {
      mt[i][j]=mt[i-1][j-1];
      //cout<<mt[i][j]<<" ";
      ans=(ans+(aa[j]-aa[i])*mt[i][j])%mod;
    }
    mt[i][n]=(mt[i-1][n]+mt[i-1][n-1])%mod;
    //cout<<mt[i][n];
    ans=(ans+(aa[n]-aa[i])*mt[i][n])%mod;
    //cout<<endl;
  }
  cout<<ans<<endl;
  //cout<<endl;
    return 0;
}