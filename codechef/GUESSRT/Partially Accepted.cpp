/****************************************************************************************
*  @author: kzvd4729                                         created: 01-02-2019 16:56:20                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k,m;cin>>n>>k>>m;
    long up=1,dw=1;long ans=0;
    while(m--)
    {
      if(!m)
      {
        ans=(ans+(up*bigmod((dw*n%mod),mod-2,mod))%mod)%mod;
      }
      else
      {
        if(n>k)n%=k;
        else
        {
          ans=(ans+(up*bigmod((dw*n%mod),mod-2,mod))%mod)%mod;
          dw=(dw*n)%mod;up=(up*(n-1))%mod;
          n+=k;
        }
      }
    }
    //cout<<n<<" "<<up<<" "<<dw<<endl;
    cout<<ans<<"\n";
  }
  return 0;
}