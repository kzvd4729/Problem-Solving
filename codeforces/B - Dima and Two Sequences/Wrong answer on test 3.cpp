/****************************************************************************************
*  @author: kzvd4729                                         created: May/13/2019 16:08                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 8000 KB                              
*  problem: https://codeforces.com/contest/273/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long fac[N+2];map<int,int>fr;
long bigmod(long b,long p,long mod)
{
  long ret=1LL;
  while(p)
  {
    if(p&1)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<pair<int,int> >v(n+n);
  for(int i=0;i<n;i++)cin>>v[i].first,v[i].second=i+1,fr[v[i].first]++;
  for(int i=n;i<n+n;i++)cin>>v[i].first,v[i].second=i-n+1,fr[v[i].first]++;
  long mod;cin>>mod;long inv=bigmod(2,mod-2,mod);
  fac[0]=1;for(int i=1;i<=N;i++)fac[i]=(fac[i-1]*i)%mod;
  sort(v.begin(),v.end());long ans=1;
  for(int i=0;i<n+n;i+=fr[v[i].first])
  {
    ans=(ans*fac[fr[v[i].first]])%mod;
    for(int j=i+1;j<n+n;j++)
    {
      if(v[j].first!=v[i].first)break;
      if(v[j].second==v[j-1].second)
        ans=(ans*inv)%mod;
    }
  }
  cout<<ans<<endl;
  return 0;
}