/****************************************************************************************
*  @author: kzvd4729                                         created: May/17/2019 17:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 16200 KB                             
*  problem: https://codeforces.com/contest/785/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long mod=1e9+7;
long fac[N+2],aa[N+2];
long bigmod(long b,long p)
{
  long ret=1;
  while(p)
  {
    if(p&1)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
long ncr(int n,int r)
{
  long ret=(fac[n]*bigmod(fac[r],mod-2))%mod;
  return (ret*bigmod(fac[n-r],mod-2))%mod;
}
int main()
{
  fac[0]=1;for(int i=1;i<=N;i++)fac[i]=(fac[i-1]*i)%mod;
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;
  for(int i=s.size()-1;i>=0;i--)
  {
    aa[i]=aa[i+1];
    if(s[i]==')')aa[i]++;
  }
  int cnt=0;long ans=0;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]==')')continue;
    ans=(ans+ncr(cnt+aa[i+1],cnt+1))%mod;
    cnt++;
  }
  cout<<ans<<endl;
  return 0;
}