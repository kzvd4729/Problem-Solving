/****************************************************************************************
*  @author: kzvd4729                                         created: May/31/2020 12:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1332/problem/E
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#define long long long
using namespace std;
const long N=1e6,mod=998244353;
long big(long b,long p)
{
  long r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
long fac[N+2];
void init()
{
  fac[0]=1;
  for(long i=1;i<=N;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
}
long ncr(long n,long r)
{
  long ret=(1LL*fac[n]*big(fac[r],mod-2))%mod;
  return (1LL*ret*big(fac[n-r],mod-2))%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  init();long n,m,l,r;cin>>n>>m>>l>>r;
  long tt=1LL*n*m;
   if(tt%2)cout<<big(r-l+1,tt)<<endl,exit(0);
  if((r-l+1)%2==0)cout<<(1LL*big(2,tt-1)*big((r-l+1)/2,tt))%mod<<endl,exit(0);
   long trl=big(r-l+1,tt)+1;
  trl*=big(2,mod-2);trl%=mod;
  cout<<trl<<endl,exit(0);
   return 0;
}