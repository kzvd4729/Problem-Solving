/****************************************************************************************
*  @author: kzvd4729                                         created: May/24/2020 14:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 234 ms                                          memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1342/problem/E
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
int strling(int n,int k)
{
  long ans=0;
  for(int i=0;i<=k;i++)
    ans=(ans+((1LL*big(-1,i)*ncr(k,i))%mod)*big(k-i,n))%mod;
  ans=(1LL*ans*big(fac[k],mod-2))%mod;
  ans=(ans+mod)%mod;
  return (1LL*ans*fac[k])%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  init();int n,k;cin>>n>>k;
  if(!k)cout<<fac[n]<<endl,exit(0);
  if(k>=n)cout<<0<<endl,exit(0);
  long ans=ncr(n,n-k);
  cout<<(2LL*ans*strling(n,n-k))%mod<<endl;
  return 0;
}