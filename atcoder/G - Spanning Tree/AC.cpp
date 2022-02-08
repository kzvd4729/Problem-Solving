/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-04 01:25:12                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 56 ms                                           memory_used: 4432 KB                              
*  problem: https://atcoder.jp/contests/jsc2021/tasks/jsc2021_g
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
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=300,inf=1e9;
const int mod=1e9+7;
 int par[N+2];
int get(int x)
{
  if(x==par[x])return x;
   return par[x]=get(par[x]);
}
 vector<int>ad[N+2];
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
int numberOfSpanningTrees(int n)
{
  vector<vector<int> >a(n+2,vector<int>(n+2,0));
  for(int i=1;i<=n;i++)
  {
    for(auto x:ad[i])a[i][x]++;
    a[i][i]=ad[i].size()*-1;
  }
  for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]*=-1;
   for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)a[i][j]=(a[i][j]+mod)%mod;
    int det=1;n--;
  for(int i=1;i<=n;i++)
  {
    if(a[i][i]==0)
    {
      for(int j=i+1;j<=n;j++)
      {
        if(a[j][i]!=0)
        {
          swap(a[i],a[j]);
          det=(det*(-1)+mod)%mod;
          break;
        }
      }
      if(a[i][i]==0)return 0;
    }
     det=(1LL*det*a[i][i])%mod;
    int ml=big(a[i][i],mod-2);
     for(int j=1;j<=n+1;j++)a[i][j]=(1LL*a[i][j]*ml)%mod;
    for(int j=i+1;j<=n;j++)
    {
      int ji=a[j][i];
      for(int k=1;k<=n+1;k++)
      {
        a[j][k]-=(1LL*a[i][k]*ji)%mod;
        a[j][k]=(a[j][k]+mod)%mod;
      }
    }
  }
  return det;
}
  int mt[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
  for(int i=1;i<=n;i++)par[i]=i;
  for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>mt[i][j];
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
     int x=mt[i][j];
       if(x==1)
      {
        int p1=get(i),p2=get(j);
        if(p1!=p2)par[p1]=p2;
        else cout<<0<<endl,exit(0);
      }
    }
  }
   for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      int x=mt[i][j];
       if(x==-1)
      {
        int p1=get(i),p2=get(j);
        if(p1!=p2)
        {
          ad[p1].push_back(p2);
          ad[p2].push_back(p1);
        }
      }
    }
  }
  for(int i=1;i<=n;i++)
  {
    int p1=get(i);
    if(p1==i)continue;
     ad[p1].push_back(i);
    ad[i].push_back(p1);
  }
   cout<<numberOfSpanningTrees(n)<<endl;
   return 0;
}