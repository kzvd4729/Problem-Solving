/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-04-27 20:45:26                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 177 ms                                          memory_used: 3816 KB                              
*  problem: https://atcoder.jp/contests/abc199/tasks/abc199_f
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e2,inf=1e9,mod=1e9+7;
 int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
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
  int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m,k;cin>>n>>m>>k;
  for(int i=0;i<n;i++)cin>>a[i];
    vector<vector<int> >ad(n);
  for(int i=0;i<m;i++)
  {
    int a,b;cin>>a>>b;a--,b--;
    ad[a].push_back(b);
    ad[b].push_back(a);
  }
   vector<vector<int> >b(n,vector<int>(n,0));
   int inv=big(m,mod-2);
  int inv2=big(2,mod-2);
   for(int i=0;i<n;i++)
  {
    int sz=ad[i].size();
    int rm=1;
    for(auto x:ad[i])
    {
      b[i][x]=(1LL*inv*inv2)%mod;
      b[i][i]=(b[i][i]+1LL*inv*inv2)%mod;
      rm=(rm-inv+mod)%mod;
    }
    b[i][i]=(b[i][i]+rm)%mod;
  }
   // for(int i=0;i<b.size();i++)
  // {
  //   for(int j=0;j<b[i].size();j++)
  //     cout<<b[i][j]<<" ";
  //   cout<<endl;
  // }
  // cout<<endl;
   b=expo(b,k);
  // for(int i=0;i<b.size();i++)
  // {
  //   for(int j=0;j<b[i].size();j++)
  //     cout<<b[i][j]<<" ";
  //   cout<<endl;
  // }
  // cout<<endl;
   vector<vector<int> >c(n);
  for(int i=0;i<n;i++)c[i]={a[i]};
   b=multiply(b,c);
   for(int i=0;i<b.size();i++)
  {
    for(int j=0;j<b[i].size();j++)
      cout<<b[i][j]<<" ";
    cout<<endl;
  }
     return 0;
}