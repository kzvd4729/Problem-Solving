/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/29/2020 00:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 4227 ms                                         memory_used: 8900 KB                              
*  problem: https://codeforces.com/gym/102644/problem/I
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
v2d power[65];//max power
void precalPower(v2d &b,long mx)
{
  power[0]=b;long p=1;
  for(int i=1;p+p<=mx;i++,p=p+p)
    power[i]=multiply(power[i-1],power[i-1]);
}
int compute(v2d v,long p,int t)//v is a column vector
{
  while(p)
  {
    long z=63-__builtin_clzll(p);
    p^=(1LL<<z);
    v=multiply(v,power[z]);
  }
  return v[0][t];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,q;cin>>n>>m>>q;
  v2d b(n);for(int i=0;i<n;i++)b[i].resize(n);
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;u--,v--;
    b[u][v]=1;
  }
  precalPower(b,1000000000);
  while(q--)
  {
    int u,v,k;cin>>u>>v>>k;u--;v--;
    v2d tmp;tmp.push_back(b[u]);
    cout<<compute(tmp,k-1,v)<<'\n';
  }
  return 0;
}