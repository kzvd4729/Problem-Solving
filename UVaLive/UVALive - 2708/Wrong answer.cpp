/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-06 16:27:57                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-2708
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;

int big(int b,int p,int m=mod)
{
  int ret=1;
  while(p)
  {
    if(p&1)ret=(1LL*ret*b)%m;
    b=(1LL*b*b)%m;p/=2;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;
  while(cin>>n)
  {
    if(n==-1)break;int k=3;
    int ans=0;
    for(int i=0;i<n;i++)
      ans=(ans+big(k,__gcd(i,n)))%mod;

    if(n%2==0)
    {
      ans=(1LL*ans+(n/2)*big(k,n/2))%mod;
      ans=(1LL*ans+(n/2)*big(k,n/2+1))%mod;
      ans=(1LL*ans*big(n+n,mod-2,mod))%mod;
      cout<<ans<<"\n";
    }
    else
    {
      ans=(ans+n*big(k,n/2+1))%mod;
      ans=(1LL*ans*big(n+n,mod-2,mod))%mod;
      cout<<ans<<"\n";
    }
  }
  return 0;
}