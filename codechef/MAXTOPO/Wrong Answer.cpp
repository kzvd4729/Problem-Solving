/****************************************************************************************
*  @author: kzvd4729                                         created: 10-03-2021 00:08:44                      
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
const int N=1e6,inf=1e9,mod=1e9+7;
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
  int ret=(1LL*fac[n]*big(fac[r],mod-2))%mod;
  return (1LL*ret*big(fac[n-r],mod-2))%mod;
}
vector<int>ad[N+2];
int n,sz[N+2];
void reckon(int nd,int pr)
{
  sz[nd]=1;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    reckon(x,nd);sz[nd]+=sz[x];
  }
}
int findCenter(int nd,int pr)
{
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    if(sz[x]>n/2)return findCenter(x,nd);
  }
  return nd;
}
int sub[N+2],tp[N+2];
void dfs(int nd,int pr)
{
  sub[nd]=0,tp[nd]=1;
  for(auto x:ad[nd])
  {
    if(x==pr)continue;
    dfs(x,nd);
    tp[nd]=(1LL*tp[nd]*tp[x])%mod;
    tp[nd]=(1LL*ncr(sub[x]+sub[nd],sub[x]))%mod;
  }
  sub[nd]++;
} 
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  init();int t;cin>>t;
  while(t--)
  {
    int k;cin>>n>>k;if(k>1)return 0;
    for(int i=1;i<=n;i++)ad[i].clear();
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      ad[u].push_back(v);ad[v].push_back(u);
    }
    reckon(1,-1);int cn=findCenter(1,-1);
    vector<int>v={cn};
    for(auto x:ad[cn])
    {
      reckon(x,-1);
      int f=1;
      for(auto z:ad[x])if(sz[z]>n/2)f=0;
      if(f)v.push_back(x);
    }
    sort(v.begin(),v.end());dfs(v.back(),-1);
    cout<<v.back()<<" "<<tp[v.back()]<<endl;
  }
  return 0;
}