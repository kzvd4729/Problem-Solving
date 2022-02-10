/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-23 18:57:02                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1246
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,mod=1e9+7;
int on,tw,dp[50+2][204][204];
int big(int b,int p,int m=mod)
{
  int ret=1;
  while(p){if(p&1)ret=(1LL*ret*b)%m;b=(1LL*b*b)%m;p/=2;}
  return ret;
}
int fac[N+2];
void init(int n)
{
  fac[0]=1;
  for(int i=1;i<=n;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
}
int ncr(int n,int r)
{
  int a=fac[n];a=(1LL*a*big(fac[r],mod-2))%mod;
  return (1LL*a*big(fac[n-r],mod-2))%mod;
}
long dfs(int k,int a,int b)
{
  if(k==0)
  {
    if(a|b)return 0;return 1;
  }
  if(dp[k][a][b]!=-1)return dp[k][a][b];
  long now=dfs(k-1,a,b);
  for(int i=1;i<=a;i++)
    now=(now+ncr(a,i)*dfs(k-1,a-i,b))%mod;
  for(int i=1;i<=b;i++)
    now=(now+ncr(b,i)*dfs(k-1,a,b-i))%mod;
  return dp[k][a][b]=now;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;init(N);memset(dp,-1,sizeof(dp));
  while(t--)
  {
    int a,b,c;cin>>a>>b>>c;a++,b++;
    int on=(a*b)/2;int tw=a*b-on;
    cout<<"Case "<<++tc<<": "<<dfs(c,on,tw)<<"\n";
  }
  return 0;
}