/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-12 18:17:03                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/Kattis-barcode
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6,inf=1e9;
int m,dp[N+2][4];
int big(int b,int p)
{
  int ret=1;
  while(p){if(p&1)ret=(1LL*ret*b)%m;b=(1LL*b*b)%m;p/=2;}
  return ret;
}
int fac[N+2];
void init(int n)
{
  fac[0]=1;
  for(int i=1;i<=n;i++)fac[i]=(1LL*fac[i-1]*i)%m;
}
int ncr(int n,int r)
{
  int a=fac[n];a=(1LL*a*big(fac[r],m-2))%m;
  return (1LL*a*big(fac[n-r],m-2))%m;
}
int dfs(int n,int f)
{
  dp[0][0]=1;dp[0][1]=1;
  for(int i=1;i<=n;i++)
  {
    dp[i][1]=dp[i-1][0];
    dp[i][0]=(dp[i-1][0]+dp[i-1][1])%m;
  }
  return dp[n][0];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n>>m;init(N);
    int ans=dfs(n,0)%m;
    if(n%2==0)
    {
      ans=(ans+ncr(n,n/2))%m;
      ans=(ans-2)%m;ans=(ans+m)%m;
    }
    cout<<ans<<"\n";
  }  
  return 0;
}