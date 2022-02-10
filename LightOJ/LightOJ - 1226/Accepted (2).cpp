/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-24 13:28:40                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 84                                         memory_used (MB): 9.5                             
*  problem: https://vjudge.net/problem/LightOJ-1226
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e3;
const long mod=1e9+7;
long n,t,tc,x;
long fac[1000006],arr[N+2];
long bigmod(long b,long p,long mod)
{
  long ret=1;
  while(p)
  {
    if(p&1)
      ret=(ret*b)%mod;
    b=(b*b)%mod;
    p/=2;
  }
  return ret%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  fac[0]=1LL;
  for(long i=1;i<=1000000;i++)
    fac[i]=(fac[i-1]*i)%mod;

  cin>>t;
  while(t--)
  {
    cin>>n;
    long sum=0,ans=1;
    for(long i=1;i<=n;i++)
    {
      cin>>x;
      sum+=x;
      if(x==1)continue;
      //cout<<sum-1<<" "<<x-1<<" ";
      long ncr=((fac[sum-1]*bigmod(fac[x-1],mod-2,mod))%mod*bigmod(fac[sum-x],mod-2,mod))%mod;
      //cout<<ncr<<endl;
      ans=(ans*ncr)%mod;
    }
    cout<<"Case "<<++tc<<": "<<ans<<endl;
  }
  return 0;
}