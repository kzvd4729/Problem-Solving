/****************************************************************************************
*  @author: kzvd4729#                                        created: May/29/2020 21:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 904 ms                                          memory_used: 24600 KB                             
*  problem: https://codeforces.com/contest/439/problem/E
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
const long N=2e5;
vector<int>dd[N+2];
void dvisors()
{
  for(int i=1;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)dd[j].push_back(i);
  }
}
const int mod=1e9+7;
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
int starsAndBars(int n,int k)
{
  return ncr(n+k-1,n);
}
int tmp[N+2];map<pair<int,int>,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  init();dvisors();int t;cin>>t;
  while(t--)
  {
    int n,f;cin>>n>>f;
    if(mp.find(make_pair(n,f))!=mp.end())
    {
      cout<<mp[{n,f}]<<"\n";continue;
    }
    for(int i=0;i<dd[n].size();i++)tmp[i]=0;
    for(int i=dd[n].size()-1;i>=0;i--)
    {
      int x=dd[n][i];if(1LL*x*f>n)continue;
      tmp[i]+=starsAndBars((n-x*f)/x,f);tmp[i]%=mod;
      for(int j=0;j<i;j++)
        if(x%dd[n][j]==0)tmp[j]=(tmp[j]-tmp[i])%mod;
    }
    mp[{n,f}]=(tmp[0]+mod)%mod;
    cout<<(tmp[0]+mod)%mod<<"\n";
  }
   return 0;
}