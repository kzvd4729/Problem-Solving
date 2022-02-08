/****************************************************************************************
*  @author: kzvd4729                                         created: 03-02-2019 10:34:27                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.18 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/FEB19B/problems/GUESSRT
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long mod=1e9+7;
long bigmod(long b,long p,long mod)
{
  long ret=1LL;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
/**************** Progressions *******************/
long AP(long n,long first,long df)
{
  long ret=2*first+(n-1)*df;
  return (ret*n)/2;
}
long GP(long n,long first,long fc)
{
  long ret=(first*(bigmod(fc,n,mod)-1))%mod;
  return (ret*bigmod(fc-1,mod-2,mod))%mod;
}
/////////////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long n,k,m;cin>>n>>k>>m;long ans=0;
    if(m%2)
    {
      long first=bigmod(n,mod-2,mod);
      long fc=((n-1)*first)%mod;
      cout<<GP((m+1)/2,first,fc)<<endl;
    }
    else
    {
      long first=bigmod(n,mod-2,mod);
      long fc=((n-1)*first)%mod;
      ans=GP(m/2,first,fc);
      long up=bigmod(n-1,m/2,mod);
      long dw=bigmod(n,m/2,mod);
      up=(up*bigmod(dw,mod-2,mod))%mod;
      ans=(ans+(up*bigmod(n+k,mod-2,mod))%mod)%mod;
      cout<<ans<<endl;
    }
  }
  return 0;
}