/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/12/2020 00:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 154 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/336/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
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
  ios_base::sync_with_stdio(0);cin.tie(0);
  init(N);
   int n,m,g;cin>>n>>m>>g;
   int ans=0;
  if((n+m)%2==1&&m==0)ans++;
  if((n+m)%2==0&&m==1)ans++;
  for(int i=1;i<n+m;i+=2)
  {
    int a=n-(i-1),b=m-1;if(a<0||b<0)continue;
    ans=(ans+ncr(n+m-i,b))%mod;
  }
  //cout<<ans<<endl;
  if(g)ans=(ncr(n+m,n)-ans+mod)%mod;
  cout<<ans<<endl;
  return 0;
}