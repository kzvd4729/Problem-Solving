/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-08-29 18:21:14                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 30                                         memory_used (MB): 4.5                             
*  problem: https://vjudge.net/problem/SPOJ-FIBTWIST
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int mod;
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
/*
used to get query faster
complexity q*logp*d^2
*/
v2d power[65];//max power
void precalPower(v2d &b,long mx)
{
  power[0]=b;long p=1;
  for(int i=1;p+p<=mx;i++,p=p+p)
    power[i]=multiply(power[i-1],power[i-1]);
}
int compute(v2d v,long p)//v is a column vector
{
  while(p)
  {
    long z=63-__builtin_clzll(p);
    p^=(1LL<<z);
    v=multiply(power[z],v);
  }
  return v[0][0];
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  v2d v(4);
  v[0].resize(4,0);v[0][0]=1,v[0][1]=1,v[0][2]=1;
  v[1].resize(4,0);v[1][0]=1;
  v[2].resize(4,0);v[2][2]=1,v[2][3]=1;
  v[3].resize(4,0);v[3][3]=1;

  int t;cin>>t;
  while(t--)
  {
    int a;cin>>a>>mod;
    if(a==0){cout<<0<<"\n";continue;}
    if(a==1){cout<<1<<"\n";continue;}

    v2d b=expo(v,a-1);
    cout<<((b[0][0]+b[0][2])%mod+b[0][3])%mod<<"\n";
  }
  return 0;
}