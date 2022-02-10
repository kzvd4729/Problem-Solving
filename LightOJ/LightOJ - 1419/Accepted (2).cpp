/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-06 16:08:26                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 33                                         memory_used (MB): 2.1                             
*  problem: https://vjudge.net/problem/LightOJ-1419
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
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    int ans=0;
    for(int i=0;i<n;i++)
      ans=(ans+big(k,__gcd(i,n)))%mod;
    ans=(1LL*ans*big(n,mod-2,mod))%mod;
    cout<<"Case "<<++tc<<": "<<ans<<"\n";
  }
  return 0;
}