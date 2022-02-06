/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 4700 KB                              
*  problem: https://codeforces.com/gym/100589/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const long mod=1e9+7;
int n,m,k;
long fac[N+N+2],dp[N+2],inv[N+N+2];
pair<int,int>pp[N+2];
long bigmod(long b,long p,long mod)
{
  long ret=1LL;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
long ncr(long n,long r)
{
  long ret=fac[n];ret=(ret*inv[r])%mod;
  ret=(ret*inv[n-r])%mod;
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  fac[0]=1;inv[0]=bigmod(fac[0],mod-2,mod);
  for(long i=1;i<=N+N;i++)
  {
    fac[i]=(fac[i-1]*i)%mod;
    inv[i]=bigmod(fac[i],mod-2,mod);
  }
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
      cin>>pp[i].first>>pp[i].second;
    pp[++k]={n,m};sort(pp+1,pp+k+1);
    for(int i=1;i<=k;i++)
    {
      dp[i]=ncr(pp[i].first+pp[i].second-2,pp[i].second-1);
      for(int j=1;j<i;j++)
      {
        if(pp[j].first>pp[i].first||pp[j].second>pp[i].second)
          continue;
        int x=pp[i].first-pp[j].first+1;
        int y=pp[i].second-pp[j].second+1;
        dp[i]=(dp[i]-(dp[j]*ncr(x+y-2,x-1))%mod+mod)%mod;
      }
    }
    cout<<dp[k]<<"\n";
  }
  return 0;
}