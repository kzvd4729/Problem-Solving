/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-12 18:27:05                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/Kattis-barcode
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e6,inf=1e9;
long m,dp[N+2][4];
long big(long b,long p)
{
  long ret=1;
  while(p){if(p&1)ret=(1LL*ret*b)%m;b=(1LL*b*b)%m;p/=2;}
  return ret;
}
long fac[N+2];
void init(long n)
{
  fac[0]=1;
  for(long i=1;i<=n;i++)fac[i]=(1LL*fac[i-1]*i)%m;
}
long ncr(long n,long r)
{
  long a=fac[n];a=(1LL*a*big(fac[r],m-2))%m;
  return (1LL*a*big(fac[n-r],m-2))%m;
}
long dfs(long n,long f)
{
  dp[0][0]=1;dp[0][1]=1;
  for(long i=1;i<=n;i++)
  {
    dp[i][1]=dp[i-1][0];
    dp[i][0]=(dp[i-1][0]+dp[i-1][1])%m;
  }
  return dp[n][0];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long n;cin>>n>>m;init(N);
    long ans=dfs(n,0)%m;
    if(n%2==0)
    {
      ans=(ans+ncr(n,n/2))%m;
      ans=(ans-n/2-1)%m;ans=(ans+m)%m;
    }
    cout<<ans<<"\n";
  }  
  return 0;
}