/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2020 18:14                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/gym/102644/problem/E
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
int knightX[]={2,1,-1,-2,-2,-1,1,2};
int knightY[]={1,2,2,1,-1,-2,-2,-1};
typedef vector<vector<unsigned int> > v2d;
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
        c[i][j]=(c[i][j]+a[i][k]*b[k][j]);
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
  int k;cin>>k;
  v2d bs(65);
  for(int i=0;i<65;i++)bs[i].resize(65);
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)
    {
      int a,b;
      for(int k=0;k<8;k++)
      {
        a=i+knightX[k],b=j+knightY[k];
        if(a>=0&&b>=0&&a<8&&b<8)bs[i*8+j][a*8+b]=1;
      }
    }
  }
  bs[64][0]=1;bs[64][64]=1;
  bs=expo(bs,k+1);
  unsigned int ans=0;
  for(int i=0;i<64;i++)ans+=bs[64][i];
  cout<<ans<<endl;
   return 0;
}