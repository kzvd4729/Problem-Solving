/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-09 21:24:38                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 560 ms                                          memory_used: 4080 KB                              
*  problem: https://atcoder.jp/contests/arc116/tasks/arc116_d
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
const int N=5000,inf=1e9,mod=998244353;
  int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
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
  int n,m,dp[20+2][N+2];
 int dfs(int id,int m)
{
  if(id<0)return (m==0);
   if(dp[id][m]!=-1)return dp[id][m];
   int ret=dfs(id-1,m);
  for(int i=2; ;i+=2)
  {
    if((1<<id)*i>m)break;
    ret=(ret+1LL*ncr(n,i)*dfs(id-1,m-(1<<id)*i))%mod;
  }
  return dp[id][m]=ret;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   init();
  cin>>n>>m;
   memset(dp,-1,sizeof dp);
  cout<<dfs(20,m)<<endl;
    return 0;
}