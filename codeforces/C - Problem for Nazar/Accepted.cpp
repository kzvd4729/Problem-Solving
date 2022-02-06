/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/22/2019 14:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1151/problem/C
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
long ap(long n,long df)
{
  long ret=(2+(n-1)*df)%mod;
  return (((ret*(n%mod)))%mod*bigmod(2,mod-2,mod))%mod;
}
long cal(long x)
{
  long p=0,odd=0,evv=0;
  for(long i=0; ;i++)
  {
    if(!x)break;
    long pw=min((1LL<<i),x);x-=pw;
    if(i%2==0)odd+=pw;
    else evv+=pw;
  }
  return (ap(odd,2)+evv+ap(evv,2))%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long l,r;cin>>l>>r;
  cout<<(cal(r)-cal(l-1)+mod)%mod<<endl;
  return 0;
}