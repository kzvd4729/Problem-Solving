/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/11/2020 20:31                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 436 ms                                          memory_used: 600 KB                               
*  problem: https://codeforces.com/contest/621/problem/E
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
const int N=1e6,mod=1e9+7;
int cnt[10+2];
typedef vector<vector<int> > v2d;
v2d multiply(v2d &a,v2d &b)
{
  int d=a.size(),e=a[0].size();
  int f=b.size(),g=b[0].size();
  if(e!=f)assert(0);
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
  int n=a.size();if(a[0].size()!=n)assert(0);
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
  int n,b,k,x;cin>>n>>b>>k>>x;
  for(int i=1;i<=n;i++)
  {
    int a;cin>>a;cnt[a%x]++;
  }
  v2d a(x);
  for(int i=0;i<x;i++)a[i].resize(x,0);
  //for(int i=0;i<x;i++)cout<<cnt[i]<<" ";cout<<endl;
    //cout<<endl;
  for(int i=0;i<x;i++)
  {
    for(int j=0;j<x;j++)
    {
      for(int d=0;d<x;d++)
      {
        if((j*10+d)%x==i)a[i][j]=cnt[d];
      }
    }
  }
  a=expo(a,b);
  /*for(int i=0;i<x;i++)
  {
    for(int j=0;j<x;j++)
      cout<<a[i][j]<<" ";
    cout<<endl;
  }*/
  cout<<a[k][0]<<endl;
  return 0;
}