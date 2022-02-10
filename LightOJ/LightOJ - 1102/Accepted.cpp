/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-22 18:17:54                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 383                                        memory_used (MB): 9.9                             
*  problem: https://vjudge.net/problem/LightOJ-1102
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6,inf=1e9;
const int mod=1e9+7;
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
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  init(N);int t,tc=0;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    cout<<"Case "<<++tc<<": "<<ncr(n+k-1,n)<<"\n";
  }
  return 0;
}