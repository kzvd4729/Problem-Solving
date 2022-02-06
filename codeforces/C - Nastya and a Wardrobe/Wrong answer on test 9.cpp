/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/12/2019 17:16                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/992/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long mod=1e9+7;
long bigmod(long b,long p,long m)
{
 long r=1;
 while(p)
 {
  if(p%2)r=(r*b)%m;
  b=(b*b)%m;p/=2;
 }
 return r;
}
long sum(long n)
{
 long ret=(n*(n+1))%mod;
 return (ret*bigmod(2,mod-2,mod))%mod;
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 long n,k;cin>>n>>k;
 long pw=bigmod(2,k,mod);
 long up=(n*pw)%mod;
 long ans=sum(up);
 ans=(ans-sum((up-pw+mod)%mod)+mod)%mod;
 ans=(ans*bigmod(pw,mod-2,mod))%mod;
 ans=(ans*2)%mod;cout<<ans<<endl;
 return 0;
}