/****************************************************************************************
*  @author: kzvd4729                                         created: 16-07-2018 01:46:46                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/JULY18A/problems/EQUILIBR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
long n,k;
long bigmod(long b,long p,long mod)
{
  long ret=1LL;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;
    p/=2;
  }
  return ret%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  cout<<(((bigmod(2LL,n-1,mod)-n+mod)%mod)*bigmod(bigmod(2LL,n-1,mod),mod-2,mod
      ))%mod<<endl;
  return 0;
}