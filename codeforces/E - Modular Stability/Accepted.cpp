/****************************************************************************************
*  @author: kzvd4729                                         created: May/28/2020 22:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 405 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1359/problem/E
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
  if(r>n)return 0;
  int ret=(1LL*fac[n]*big(fac[r],mod-2))%mod;
  return (1LL*ret*big(fac[n-r],mod-2))%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  init();int n,k;cin>>n>>k;
  long ans=0;
  for(int i=1;i<=n;i++)
  {
    int ml=n/i;ans+=ncr(ml-1,k-1);
    ans%=mod;
  }
  cout<<ans<<endl;
   return 0;
}