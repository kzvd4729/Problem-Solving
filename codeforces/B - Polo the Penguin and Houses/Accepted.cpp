/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/27/2018 15:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/288/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long mod=1e9+7;
long bigmod(long b,long p,long mod)
{
  long ret=1;
  while(p)
  {
    if(p%2==1)ret=(ret*b)%mod;
    b=(b*b)%mod;
    p/=2;
  }
  return ret%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  cout<<(bigmod(n-k,n-k,mod)*bigmod(k,k-1,mod))%mod<<endl;
  return 0;
}