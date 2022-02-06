/****************************************************************************************
*  @author: kzvd4729                                         created: May/10/2019 22:58                        
*  solution_verdict: Time limit exceeded on test 7           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 195900 KB                            
*  problem: https://codeforces.com/contest/1156/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
const long mod=998244353;
int fr[N+2],n;long dp[N+2][N+2];
long bigmod(long b,long p,long mod)
{
  long ret=1;
  while(p)
  {
    if(p&1)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
long frc(long up,long dw)
{
  return (up*bigmod(dw,mod-2,mod))%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;fr[x]++;
  }
  for(int ls=n;ls>=1;ls--)
  {
    for(int rm=1;rm<n;rm++)
    {
      dp[ls][rm]=frc(fr[ls]-1,rm);
      for(int i=ls+1;i<=n;i++)
        dp[ls][rm]+=(frc(fr[i],rm)*dp[i][rm-1])%mod;
      dp[ls][rm]%=mod;
    }
  }
  long ans=0;
  for(int i=1;i<=n;i++)
    if(fr[i])ans+=(frc(fr[i],n)*dp[i][n-1])%mod;
  cout<<ans%mod<<endl;
  return 0;
}