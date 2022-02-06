/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/15/2020 13:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 560 ms                                          memory_used: 11000 KB                             
*  problem: https://codeforces.com/contest/258/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,mod=1e9+7;
vector<int>v[N+2];
int cnt[N+2];
void dd()
{
  for(int i=1;i<=N;i++)
  {
    for(int j=i+i;j<=N;j+=i)
      v[j].push_back(i);
  }
}
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
int fac[N+2];
void init()
{
  fac[0]=1;
  for(int i=1;i<=N;i++)fac[i]=(1LL*fac[i-1]*i)%mod;
}
int ncr(int n,int r)
{
  int ret=(1LL*fac[n]*big(fac[r],mod-2))%mod;
  return (1LL*ret*big(fac[n-r],mod-2))%mod;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  init();dd();int n;cin>>n;vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
   sort(a.begin(),a.end());
  int ans=0,nn=n;
  for(int i=N;i>=1;i--)
  {
    n=nn;
    int id=n-(lower_bound(a.begin(),a.end(),i)-a.begin());
    if(id==0)continue;
     int now=(big(v[i].size()+1,id)-big(v[i].size(),id)+mod)%mod;
    n-=id;
     for(int j=v[i].size()-1;j>=0;j--)
    {
      id=n-(lower_bound(a.begin(),a.end(),v[i][j])-a.begin());
      now=(1LL*now*big(j+1,id))%mod;n-=id;
    }
    ans=(ans+now)%mod;
  }
  cout<<ans<<endl;
  return 0;
}