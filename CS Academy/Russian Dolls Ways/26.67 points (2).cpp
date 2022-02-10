/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: 26.67 points                            language: C++                                     
*  run_time: 65 ms                                           memory_used: 1924 KB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
const int N=1e5;
long mx,fact[N+2],n,cnt,ans,arr[N+2];
long bigmod(long b,long p,long mod)
{
  long ret=1;
  while(p)
  {
    if(p&1)ret=(ret*b)%mod;
    b=(b*b)%mod;
    p/=2;
  }
  return ret%mod;
}
long ncr(long n,long r)
{
  return (fact[n]*bigmod(fact[n-r],mod-2,mod))%mod;
}
int main()
{
  fact[0]=1;
  for(int i=1;i<=N;i++)fact[i]=(fact[i-1]*i)%mod;
  cin>>n;
  for(int i=1;i<=n;i++)cin>>arr[i];
  sort(arr+1,arr+n+1);
  cnt=1;
  arr[n+1]=-1;
  for(int i=2;i<=n+1;i++)
  {
    if(arr[i]==arr[i-1])cnt++;
    else
    {
      mx=max(mx,cnt);
      cnt=1;
    }
  }
  cnt=1;
  ans=1;
  for(int i=2;i<=n;i++)
  {
    if(arr[i]==arr[i-1])cnt++;
    else
    {
      ans=(ans*ncr(mx,cnt))%mod;
      cnt=1;
    }
  }
  cout<<ans%mod<<endl;
  return 0;
}