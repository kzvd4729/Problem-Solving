/****************************************************************************************
*  @author: kzvd4729                                         created: May/01/2020 12:36                        
*  solution_verdict: Time limit exceeded on test 7           language: GNU C++14                               
*  run_time: 8000 ms                                         memory_used: 119800 KB                            
*  problem: https://codeforces.com/contest/655/problem/F
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
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int big(int b,int p,int m=mod)
{
  int ret=1;
  while(p){if(p&1)ret=(1LL*ret*b)%m;b=(1LL*b*b)%m;p/=2;}
  return ret;
}
int fac[N+2];
void init()
{
  fac[0]=1;
  for(int i=1;i<=N;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
}
int ncr(int n,int r)
{
  int a=fac[n];a=(1LL*a*big(fac[r],mod-2))%mod;
  return (1LL*a*big(fac[n-r],mod-2))%mod;
}
vector<int>d[N+2];
void divisors()
{
  for(int i=1;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)
      d[j].push_back(i);
  }
  for(int i=1;i<=N;i++)
    reverse(d[i].begin(),d[i].end());
}
int nc[N+2];int cnt[N+2],tmp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  divisors();init();int n,k,q;cin>>n>>k>>q;
  for(int i=k-1;i<=N;i++)nc[i]=ncr(i,k-1);
  int ans=0;
  for(int i=1;i<=n+q;i++)
  {
    int nm;cin>>nm;
    for(auto x:d[nm])
    {
      long ch=nc[cnt[x]]+tmp[x];
      ans=(ans+ch*x)%mod;
      for(auto &z:d[x])tmp[z]=(tmp[z]-ch)%mod;
      cnt[x]++;tmp[x]=0;
    }
    if(i>n)cout<<(ans+mod)%mod<<"\n";
  }
  return 0;
}