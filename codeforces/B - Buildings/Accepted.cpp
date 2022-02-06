/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/06/2020 00:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/101873/problem/B
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
  int n,m,k;cin>>n>>m>>k;
  int bs=big(k,n*n),ans=0;
  for(int i=0;i<m;i++)
    ans=(ans+big(bs,__gcd(i,m)))%mod;
  ans=(1LL*ans*big(m,mod-2,mod))%mod;
  cout<<ans<<endl;
  return 0;
}