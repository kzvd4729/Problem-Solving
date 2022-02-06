/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/23/2018 17:29                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/697/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
const int N=1e5;
long n,arr[N+2],sum;
long bigmod(long b,long p,long mod)
{
  long ret=1LL;
  while(p)
  {
    if(p&1)ret=(ret*b)%mod;
    b=(b*b)%mod;
    p/=2;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  long up=1,dw=1;
  int f=0,one=0;
  for(int i=1;i<=n;i++)
  {
    if(arr[i]==1&&one)continue;
    if(arr[i]==1)one=1;
    if(arr[i]%2==0)f=1;
    up=up*bigmod(2,arr[i],mod);
  }
  up=(up*bigmod(2,mod-2,mod))%mod;
  dw=up;
  if(f)up=(up+1)%mod;
  else up=(up-1+mod)%mod;
  up=(up*bigmod(3,mod-2,mod))%mod;
  cout<<up<<"/"<<dw<<endl;
  return 0;
}