/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/17/2019 21:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1195/problem/D1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
const long mod=998244353;
long aa[N+2],pw[32];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pw[0]=1;
  for(long i=1;i<=30;i++)
    pw[i]=(pw[i-1]*10LL)%mod;
   long n;cin>>n;
  for(long i=1;i<=n;i++)cin>>aa[i];
  long x=aa[1],dg=0;
  while(x){x/=10;dg++;}
  long ans=0;
  for(long i=1;i<=n;i++)
  {
    long x=aa[i],p=0;
    while(x)
    {
      long rm=x%10;x/=10;
      ans=(ans+rm*pw[p++]*n)%mod;
      ans=(ans+rm*pw[p++]*n)%mod;
    }
  }
  cout<<ans<<endl;
  return 0;
}