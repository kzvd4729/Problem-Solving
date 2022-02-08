/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-04-12 18:28:39                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 16 ms                                           memory_used: 4376 KB                              
*  problem: https://atcoder.jp/contests/abc162/tasks/abc162_e
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
long cl[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
   for(int i=1;i<=k;i++)
    cl[i]=big((k/i),n);
  for(int i=k;i>=1;i--)
  {
    for(int j=i+i;j<=k;j+=i)
      cl[i]=(cl[i]-cl[j]+mod)%mod;
  }
  long ans=0;
  for(int i=1;i<=k;i++)
    ans=(ans+cl[i]*i)%mod;
  cout<<ans<<endl;
   return 0;
}