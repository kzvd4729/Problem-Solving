/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/13/2020 14:11                        
*  solution_verdict: Time limit exceeded on test 20          language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1334/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=998244353;
int fac[N+2],inv[N+2];
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  fac[0]=1;
  for(int i=1;i<=N;i++)
  {
    fac[i]=(1LL*fac[i-1]*i)%mod;
    inv[i]=big(fac[i],mod-2);
  }
   long x;cin>>x;int sq=sqrt(x+2);
  vector<int>p;
  for(int i=2;i<=x;i++)
  {
    if(x%i)continue;p.push_back(i);
    while(x%i==0)x/=i;
  }
  if(x>1)p.push_back(x);
  int q;cin>>q;
  while(q--)
  {
    long u,v;cin>>u>>v;if(u>v)swap(u,v);
    long d=__gcd(u,v);u/=d;v/=d;
    long ans=1;
     int tt=0;
    for(auto x:p)
    {
      if(u%x)continue;int cnt=0;
      while(u%x==0)u/=x,cnt++;
      tt+=cnt;ans=(ans*inv[cnt])%mod;
    }
    ans=(ans*fac[tt])%mod;
     tt=0;
    for(auto x:p)
    {
      if(v%x)continue;int cnt=0;
      while(v%x==0)v/=x,cnt++;
      tt+=cnt;ans=(ans*inv[cnt])%mod;
    }
    ans=(ans*fac[tt])%mod;
    cout<<ans<<"\n";
  }
  return 0;
}