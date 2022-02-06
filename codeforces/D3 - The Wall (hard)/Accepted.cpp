/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/27/2019 17:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1404 ms                                         memory_used: 8400 KB                              
*  problem: https://codeforces.com/contest/690/problem/D3
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,mod=1e6+3;
int len[N+2],dp[N+2];
int big(int b,int p)
{
  int ret=1;
  while(p)
  {
    if(p%2)ret=(1LL*ret*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return ret;
}
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
inline ret(int id)
{
  if(id==-1)return 1;
  return dp[id];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int c,w,h;cin>>c>>w>>h;
  for(int i=1;i<=w;i++)len[i]=big(h,i)%mod;
   dp[0]=1;
  for(int i=1;i<=min(c,N);i++)
  {
    dp[i]=dp[i-1];
    for(int ln=1;ln<=min(i,w);ln++)
      dp[i]=(dp[i]+1LL*len[ln]*ret(i-ln-1))%mod;
  }
  if(c<=N)cout<<dp[c]<<"\n",exit(0);
  v2d bs;bs.resize(w+1);
  for(int i=0;i<w+1;i++)
    bs[i].resize(w+1);
  bs[0][0]=1;
  for(int i=1;i<w+1;i++)
    bs[0][i]=len[i];
  for(int i=1;i<w+1;i++)
    bs[i][i-1]=1;
  bs=expo(bs,c-w);
  int ans=0;int id=w;
  for(int i=0;i<w+1;i++)
    ans=(ans+1LL*bs[0][i]*dp[id--])%mod;
  cout<<ans<<endl;
  return 0;
}