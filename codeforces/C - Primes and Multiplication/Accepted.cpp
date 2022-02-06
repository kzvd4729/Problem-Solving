/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/29/2019 19:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1228/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e3,mod=1e9+7;
vector<long>v;
long big(long b,long p)
{
  long ret=1;
  while(p)
  {
    if(p%2)ret=(1LL*ret*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return ret;
}
void facto(long x)
{
  long sq=sqrt(x+2);
  for(long i=2;i<=sq;i++)
  {
    if(x%i==0)
    {
      v.push_back(i);
      while(x%i==0)x/=i;
    }
  }
  if(x>1)v.push_back(x);
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long x;long n;cin>>x>>n;facto(x);
  long ans=1;
  for(auto x:v)
  {
    long nm=x;//cout<<"*"<<x<<endl;
    while(true)
    {
      long cnt=n/nm;if(cnt==0)break;
      ans=(ans*(big(x,cnt)))%mod;
      if(n/nm<x)break;
      nm=nm*x;
    }
  }
  cout<<ans<<endl;
  return 0;
}