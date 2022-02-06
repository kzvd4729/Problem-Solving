/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2020 20:01                        
*  solution_verdict: Runtime error on test 4                 language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 4000 KB                              
*  problem: https://codeforces.com/gym/102644/problem/G
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
int a[10+2],c[10+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;long k;cin>>n>>k;
   for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>c[i];
   int p,q,r;cin>>p>>q>>r;
   if(k<n)assert(0);
    v2d b(n+6);
  for(int i=0;i<n+6;i++)b[i].resize(n+6);
   int qq=(1LL*n*q)%mod;
  int rr=(1LL*n*n*r)%mod;
  int ir=(1LL*n*r)%mod;
   for(int i=0;i<n;i++)b[0][i]=c[0];
  for(int i=n;i<n+3;i++)b[0][i]=1;
   for(int i=1;i<n;i++)b[i][i-1]=1;
   b[n][n]=1;
  b[n+1][n+1]=1;b[n+1][n+3]=1;
  b[n+2][n+2]=1;b[n+2][n+5]=2;b[n+2][n+4]=1;
  b[n+3][n+3]=1;
  b[n+4][n+4]=1;
  b[n+5][n+5]=1;b[n+5][n+4]=1;
   b=expo(b,k-n+1);
   int ans=0;
  for(int i=0;i<n;i++)ans=(ans+1LL*b[0][i]*a[n-i-1])%mod;
  ans=(ans+1LL*p*b[0][n])%mod;
  ans=(ans+1LL*qq*b[0][n+1])%mod;
  ans=(ans+1LL*rr*b[0][n+2])%mod;
  ans=(ans+1LL*q*b[0][n+3])%mod;
  ans=(ans+1LL*r*b[0][n+4])%mod;
  ans=(ans+1LL*ir*b[0][n+5])%mod;
   cout<<ans<<endl;
     return 0;
}