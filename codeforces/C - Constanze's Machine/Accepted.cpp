/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/01/2019 21:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/1245/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
const long mod=1e9+7;
long fac[N+2];
long big(long b,long p)
{
  long ret=1;
  while(p)
  {
    if(p&1)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
long ncr(long n,long r)
{
  //cout<<n<<" --> "<<r<<endl;
  long ret=fac[n];
  ret=(ret*big(fac[r],mod-2))%mod;
  ret=(ret*big(fac[n-r],mod-2))%mod;
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   fac[0]=1;
  for(long i=1;i<=N;i++)fac[i]=(fac[i-1]*i)%mod;
   string s;cin>>s;
  for(auto x:s)
    if(x=='w'||x=='m')cout<<0<<endl,exit(0);
   long cnt=0;long ans=1;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='u')  
    {
      long cnt=0,j;
      for(j=i;j<s.size();j++)
      {
        if(s[j]!='u')break;
        cnt++;
      }
      long ml=0;
      for(int j=0;j<=cnt;j++)
      {
        if(j*2>cnt)break;
        ml=(ml+ncr(cnt-j,j))%mod;
      }
      ans=(ans*ml)%mod;
      i=j-1;
    }
    else if(s[i]=='n')
    {
      long cnt=0,j;
      for(j=i;j<s.size();j++)
      {
        if(s[j]!='n')break;
        cnt++;
      }
      long ml=0;
      for(int j=0;j<=cnt;j++)
      {
        if(j*2>cnt)break;
        ml=(ml+ncr(cnt-j,j))%mod;
      }
      ans=(ans*ml)%mod;
      i=j-1;
    }
  }
  cout<<ans<<endl;
  return 0;
}