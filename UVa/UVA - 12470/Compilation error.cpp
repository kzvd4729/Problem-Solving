/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-08-29 15:48:34                      
*  solution_verdict: Compilation error                       language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12470
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const int mod=1e9+7;

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
v2d expo(v2d &a,long p)
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
  dont compile.
  ios_base::sync_with_stdio(0);cin.tie(0);
  v2d b(3);for(int i=0;i<3;i++)v[i].resize(3,0);
  v[0][0]=1;v[0][1]=1;v[0][2]=1;
  v[1][0]=1;v[2][1]=1;
  while(cin>>n)
  {
    if(!n)break;
    if(n==1){cout<<0<<endl;continue;}
    else if(n==2){cout<<1<<endl;continue;}
    else if(n==3){cout<<2<<endl;continue;}

    b=expo()

  }
  return 0;
}