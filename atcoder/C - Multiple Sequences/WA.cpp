/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-09 20:49:36                      
*  solution_verdict: WA                                      language: C++ (GCC 9.2.1)                         
*  run_time: 299 ms                                          memory_used: 45736 KB                             
*  problem: https://atcoder.jp/contests/arc116/tasks/arc116_c
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
const long N=1e6,inf=1e9,mod=998244353;
 long dp[N+2][20+2];
  long big(long b,long p,long m=mod)
{
  long ret=1;
  while(p){if(p&1)ret=(1LL*ret*b)%m;b=(1LL*b*b)%m;p/=2;}
  return ret;
}
long fac[N+2];
void init(long n)
{
  fac[0]=1;
  for(long i=1;i<=n;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
}
long ncr(long n,long r)
{
  long a=fac[n];a=(1LL*a*big(fac[r],mod-2))%mod;
  return (1LL*a*big(fac[n-r],mod-2))%mod;
}
 long starsAndBars(long n,long k)
{
  return ncr(n+k-1,n);
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long n,m;cin>>n>>m;
   for(long i=1;i<=m;i++)dp[i][1]=1;
   for(long i=1;i<m;i++)
  {
    for(long j=1;j<=20;j++)
    {
      for(long ii=i+i;ii<=m;ii+=i)
        dp[ii][j]=(dp[ii][j]+dp[i][j-1])%mod;
    }
  }
   init(N);
   long ans=0;
  for(long i=1;i<=20;i++)
  {
    if(i>m)continue;
    long tt=0;
    for(long j=1;j<=m;j++)tt=(tt+dp[j][i])%mod;
     //cout<<i<<" "<<tt<<" "<<starsAndBars(m-i,i)*tt<<endl;
     //cout<<m-i<<" "<<i<<" "<<starsAndBars(m-i,i)<<endl;
     ans=(ans+1LL*starsAndBars(n-i,i)*tt)%mod;
  }
  cout<<ans<<endl;
      return 0;
}