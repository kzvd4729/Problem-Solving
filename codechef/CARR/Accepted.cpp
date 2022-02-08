/****************************************************************************************
*  @author: kzvd4729                                         created: 25-01-2020 20:07:19                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 1.15 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/LTIME80A/problems/CARR
****************************************************************************************/
#include<bits/stdc++.h>
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
  int t;cin>>t;
  while(t--)
  {
    long n,k;cin>>n>>k;k%=mod;
    v2d b(2);b[0].resize(2),b[1].resize(2);
    b[0][0]=(k-1+mod)%mod,b[0][1]=(k-1+mod)%mod;
    b[1][0]=1,b[1][1]=0;
    b=expo(b,n-1);
    //cout<<b[0][0]<<" "<<b[0][1]<<endl<<b[1][0]<<" "<<b[1][1]<<endl;
    long ans=(1LL*(b[0][0]+b[1][0])*k)%mod;
    cout<<(ans+mod)%mod<<"\n";
  }
  return 0;
}