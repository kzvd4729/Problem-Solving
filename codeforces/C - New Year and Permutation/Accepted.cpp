/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/04/2020 18:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1284/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
long fac[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,mod;cin>>n>>mod;
   fac[0]=1;
  for(long i=1;i<=n;i++)
    fac[i]=(1LL*fac[i-1]*i)%mod;
  long ans=0;
  for(long i=1;i<=n;i++)
  {
    long ad=((n-i+1)*fac[i])%mod;
    ad=(ad*fac[n-i])%mod;ad=(ad*(n-i+1))%mod;
     ans=(ans+ad)%mod;
  }
  cout<<ans<<endl;
  return 0;
}