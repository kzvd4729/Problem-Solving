/****************************************************************************************
*  @author: kzvd4729                                         created: 10-03-2021 00:25:00                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/MARCH21A/problems/MAXTOPO
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
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long N=5e5,inf=1e9,mod=1e9+7;
long big(long b,long p)
{
  long r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
long fac[N+2],inv[N+2];
void init()
{
  fac[0]=1;
  for(long i=1;i<=N;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
  for(long i=0;i<=N;i++)inv[i]=big(fac[i],mod-2);
}
long ncr(long n,long r)
{
  long ret=(1LL*fac[n]*inv[r])%mod;
  return (1LL*ret*inv[n-r])%mod;
}
vector<long>ad[N+2];
long n,sz[N+2];
void reckon(long nd,long pr)
{
  sz[nd]=1;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    reckon(x,nd);sz[nd]+=sz[x];
  }
}
long findCenter(long nd,long pr)
{
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    if(sz[x]>n/2)return findCenter(x,nd);
  }
  return nd;
}
long sub[N+2],tp[N+2];
void dfs(long nd,long pr)
{
  sub[nd]=0,tp[nd]=1;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    dfs(x,nd);
    tp[nd]=(1LL*tp[nd]*tp[x])%mod;
    tp[nd]=(1LL*tp[nd]*ncr(sub[x]+sub[nd],sub[x]))%mod;
    sub[nd]+=sub[x];
  }
  sub[nd]++;
} 
int main()
{
  init();long t;scanf("%d",&t);
  while(t--)
  {
    long k;scanf("%d%d",&n,&k);if(k>1)return 0;
    for(long i=1;i<=n;i++)ad[i].clear();
    for(long i=1;i<n;i++)
    {
      long u,v;scanf("%d%d",&u,&v);
      ad[u].push_back(v);ad[v].push_back(u);
    }
    reckon(1,-1);long cn=findCenter(1,-1);
    vector<long>v={cn};
    if(cn<1||cn>n)assert(0);
    for(auto x:ad[cn])
    {
      reckon(x,-1);
      long f=1;
      for(auto z:ad[x])if(sz[z]>n/2)f=0;
      if(f)v.push_back(x);
    }
    sort(v.begin(),v.end());dfs(v.back(),-1);
    printf("%d %d\n",v.back(),tp[v.back()]);
  }
  return 0;
}