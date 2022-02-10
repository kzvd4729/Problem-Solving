/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-04-20 22:24:31                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1407                                       memory_used (MB): 0.8                             
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
const int mod=9973;
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
  for(int i=0;i<gc.size();i++)cn[i]%=mod;
  //for(int i=0;i<gc.size();i++)cout<<gc[i]<<" ";cout<<endl;
  //for(int i=0;i<gc.size();i++)cout<<cn[i]<<" ";cout<<endl;
}
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(r*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return r;
}
int a[10+2][10+2],r[10+2][10+2],str[10+2][10+2],tmp[10+2][10+2];
void multiply1(int n)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      tmp[i][j]=0;
      for(int k=0;k<n;k++)
        tmp[i][j]=(tmp[i][j]+r[i][k]*a[k][j])%mod;
    }
  }
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)r[i][j]=tmp[i][j];
}
void multiply2(int n)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      tmp[i][j]=0;
      for(int k=0;k<n;k++)
        tmp[i][j]=(tmp[i][j]+a[i][k]*a[k][j])%mod;
    }
  }
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)a[i][j]=tmp[i][j];
}
void expo(int p,int n)
{
  for(int i=0;i<n;i++)for(int j=0;j<n;j++)r[i][j]=0;
  for(int i=0;i<n;i++)r[i][i]=1;
  while(p)
  {
    if(p&1)multiply1(n);
    multiply2(n);p/=2;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,k;cin>>n>>m>>k;aRURoiqpurafskOAIJKH(n);
    for(int i=0;i<m;i++)for(int j=0;j<m;j++)a[i][j]=1;
    for(int i=0;i<k;i++)
    {
      int u,v;cin>>u>>v;u--,v--;
      a[u][v]=0;a[v][u]=0;
    }
    for(int i=0;i<m;i++)for(int j=0;j<m;j++)str[i][j]=a[i][j];
    int sm=0;
    for(int i=0;i<gc.size();i++)
    {
      for(int j=0;j<m;j++)for(int k=0;k<m;k++)a[j][k]=str[j][k];
      expo(gc[i],m);
      /*for(int j=0;j<m;j++)
      {
        for(int k=0;k<m;k++)
          cout<<a[j][k]<<" ";
        cout<<endl;
      }
      cout<<endl;*/
      for(int j=0;j<m;j++)sm=(sm+cn[i]*r[j][j])%mod;
    }
    int inv=big(n%mod,mod-2);//cout<<sm<<endl;
    cout<<(sm*inv)%mod<<"\n";
  }
  return 0;
}