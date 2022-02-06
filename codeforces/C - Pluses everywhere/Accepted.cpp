/****************************************************************************************
*  @author: kzvd4729                                         created: May/03/2020 17:36                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 12000 KB                             
*  problem: https://codeforces.com/contest/521/problem/C
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
const int N=1e6;
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
int fac[N+2],pw[N+2];
void init()
{
  fac[0]=1;
  for(int i=1;i<=N;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
   pw[0]=1;
  for(int i=1;i<=N;i++)pw[i]=(pw[i-1]*10LL)%mod;
}
int ncr(int n,int r)
{
  if(r>n)return 0;
  int ret=(1LL*fac[n]*big(fac[r],mod-2))%mod;
  return (1LL*ret*big(fac[n-r],mod-2))%mod;
}
int qm[N+2];
void df(string s)
{
  int ans=0;
  for(int i=0;i<s.size();i++)
    ans=(ans*10LL+s[i]-'0')%mod;
  cout<<ans<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;string s;cin>>s;init();
  if(k==0)df(s);
  for(int i=1;i<=n;i++)
  {
    qm[i]=(1LL*pw[i-1]*ncr(n-1-i,k-1))%mod;
    qm[i]=(qm[i]+qm[i-1])%mod;
  }
  int id=0,ans=0;
  for(int i=s.size()-1;i>=0;i--)
  {
    int now=qm[id];now=(now+1LL*pw[id]*ncr(n-1-id,k))%mod;
    //cout<<now<<endl;
    ans=(ans+1LL*(s[i]-'0')*now)%mod;id++;
  }
  cout<<ans<<endl;
  return 0;
}