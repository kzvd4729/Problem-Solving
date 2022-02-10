/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-04-20 21:28:03                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-2888
****************************************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<assert.h>
#define long long long
using namespace std;
const int N=1e6;
vector<int>gc,cn;
void aRURoiqpurafskOAIJKH(int n)
{
  gc.clear();cn.clear();
  for(int i=1;i*i<=n;i++)
  {
    if(n%i)continue;gc.push_back(i);
    if(n/i!=i)gc.push_back(n/i);
  }
  sort(gc.begin(),gc.end());
  for(int i=0;i<gc.size();i++)cn.push_back(0);

  for(int i=gc.size()-1;i>=0;i--)
  {
    cn[i]+=n/gc[i];
    for(int j=0;j<i;j++)
      if(gc[i]%gc[j]==0)cn[j]-=cn[i];
  }
  //for(int i=0;i<gc.size();i++)cout<<gc[i]<<" ";cout<<endl;
  //for(int i=0;i<gc.size();i++)cout<<cn[i]<<" ";cout<<endl;
}
typedef vector<vector<int> > v2d;
const int mod=9973;
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
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
        c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
  }
  return c;
}
v2d expo(v2d a,int p)
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
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,k;cin>>n>>m>>k;aRURoiqpurafskOAIJKH(n);
    v2d a(m);for(int i=0;i<m;i++)for(int j=0;j<m;j++)a[i].push_back(1);
    for(int i=0;i<k;i++)
    {
      int u,v;cin>>u>>v;u--,v--;
      a[u][v]=0;a[v][u]=0;
    }
    int sm=0;
    for(int i=0;i<gc.size();i++)
    {
      v2d b=expo(a,gc[i]);
      /*for(int i=0;i<m;i++)
      {
        for(int j=0;j<m;j++)cout<<b[i][j]<<" ";
          cout<<endl;
      }
      cout<<endl;*/
      for(int j=0;j<m;j++)sm=(1LL*sm+1LL*cn[i]*b[j][j])%mod;
    }
    int inv=big(n%mod,mod-2);//cout<<sm<<endl;
    cout<<(sm*inv)%mod<<endl;
  }
  return 0;
}