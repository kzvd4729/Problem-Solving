/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/18/2020 12:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 748 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/938/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int fac[N+2];
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
void init(int n)
{
  fac[0]=1;
  for(int i=1;i<=n;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
   for(int i=1;i<=n;i++)fac[i]=(1LL*fac[n]*big(i,mod-2))%mod;
  //for(int i=1;i<=n;i++)cout<<fac[i]<<" ";cout<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;init(n);vector<int>v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  sort(v.begin(),v.end());
  int ans=0;
  for(int i=0;i<n;i++)
  {
    if(v[i]==v.back())break;
    int sm=lower_bound(v.begin(),v.end(),v[i])-v.begin();
    ans=(ans+(1LL*fac[n-sm]*v[i])%mod)%mod;
  }
  cout<<ans<<endl;
  return 0;
}