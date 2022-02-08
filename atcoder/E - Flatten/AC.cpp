/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-19 18:21:49                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 305 ms                                          memory_used: 65408 KB                             
*  problem: https://atcoder.jp/contests/abc152/tasks/abc152_e
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
 vector<int>fac[N+2];int vis[N+2];
void seive()
{
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      vis[j]=1;fac[j].push_back(i);
    }
  }
}
int mx[N+2],aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive();
   int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int z;cin>>z;int xx=z;aa[i]=z;
    for(auto x:fac[z])
    {
      int cnt=0;
      while(xx%x==0)xx/=x,cnt++;
      mx[x]=max(mx[x],cnt);
    }
  }
  long lcm=1;
  for(int i=1;i<=N;i++)
    lcm=(lcm*big(i,mx[i]))%mod;
  long ans=0;
  for(int i=1;i<=n;i++)
    ans=(ans+lcm*big(aa[i],mod-2))%mod;
  cout<<ans<<endl;
   return 0;
}