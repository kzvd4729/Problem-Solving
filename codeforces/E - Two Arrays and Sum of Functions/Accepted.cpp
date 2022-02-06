/****************************************************************************************
*  @author: * kzvd4729                                       created: May/14/2019 21:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 156 ms                                          memory_used: 26600 KB                             
*  problem: https://codeforces.com/contest/1165/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long aa[N+2],bb[N+2];
long cc[N+2];
const long mod=998244353;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=1;i<=n;i++)cin>>aa[i];
  for(long i=1;i<=n;i++)cin>>bb[i];
  long ad=n;
  for(long i=1;i<=n/2;i++)
  {
    cc[i]=cc[i-1]+ad;cc[n-i+1]=cc[i];
    ad-=2;
  }
  if(n%2)cc[n/2+1]=cc[n/2]+1;
   vector<long>v;
  for(long i=1;i<=n;i++)
    v.push_back(aa[i]*cc[i]);
   sort(v.begin(),v.end(),greater<long>());
  sort(bb+1,bb+n+1);
   long ans=0;
  for(long i=1;i<=n;i++)
    ans=(ans+((bb[i]%mod)*(v[i-1]%mod)))%mod;
  cout<<ans<<endl;
  return 0;
}