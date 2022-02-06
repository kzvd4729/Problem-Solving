/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2020 15:34                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 607 ms                                          memory_used: 4500 KB                              
*  problem: https://codeforces.com/gym/102644/problem/D
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=1e6,mod=1e9+7;
typedef vector<vector<int> > v2d;
/*
1 1 1   f[n]       f[n+1]
1 0 0 X f[n-1]  =  f[n]
0 1 0   f[n-2]     f[n-1]
*/
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  v2d b(n);
  for(int i=0;i<n;i++)b[i].resize(n);
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;u--,v--;
    b[u][v]=1;
  }
  b=expo(b,k);
  int ans=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)ans=(ans+b[i][j])%mod;
  }
  cout<<ans<<endl;
   return 0;
}