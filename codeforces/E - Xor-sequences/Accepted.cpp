/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/15/2019 17:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1169 ms                                         memory_used: 8400 KB                              
*  problem: https://codeforces.com/contest/691/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
typedef vector<vector<int> > v2d;
v2d multiply(v2d &a,v2d &b)
{
  int d=a.size(),e=a[0].size();
  int f=b.size(),g=b[0].size();
  if(e!=f)assert(0);//impossible to multiply
  v2d c;c.resize(d);
  for(int i=0;i<d;i++)
  {
    c[i].resize(g,0);
    for(int j=0;j<g;j++)
      for(int k=0;k<e;k++)
        c[i][j]=(c[i][j]+1LL*a[i][k]*b[k][j])%mod;
  }
  return c;
}
v2d expo(v2d a,long p)
{
  int n=a.size();if(a[0].size()!=n)assert(0);//impossible
  v2d ret;ret.resize(n);
  for(int i=0;i<n;i++)ret[i].resize(n);
  for(int i=0;i<n;i++)ret[i][i]=1;
  while(p)
  {
    if(p&1)ret=multiply(ret,a);
    a=multiply(a,a);p/=2;
  }
  return ret;
}
long aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;long k;cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  v2d bs(n);
  for(int i=0;i<n;i++)bs[i].resize(n,0);
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      if(__builtin_popcountll(aa[i]^aa[j])%3==0)bs[i-1][j-1]=1;
  }
  bs=expo(bs,k-1);
//  for(auto x:bs)
//  {
//    for(auto z:x)
//      cout<<z<<" ";
//    cout<<endl;
//  }
  //bs=expo(bs,k);
  long ans=0;
  for(auto x:bs)for(auto z:x)ans=(ans+z)%mod;
  cout<<ans<<endl;
  return 0;
}