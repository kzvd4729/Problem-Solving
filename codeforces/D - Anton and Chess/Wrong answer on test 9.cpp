/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/04/2020 11:37                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 311 ms                                          memory_used: 8800 KB                              
*  problem: https://codeforces.com/contest/734/problem/D
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
#define long long long
using namespace std;
const int N=1e6;
int a[N+2],b[N+2];char c[N+2];
void yes(){cout<<"YES\n",exit(0);}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,x,y;cin>>n>>x>>y;
   for(int i=1;i<=n;i++)
  {
    cin>>c[i]>>a[i]>>b[i];
    if(a[i]==x&&b[i]==y)assert(0);
  }
  int mn=2e9+1;char f='a';
  for(int i=1;i<=n;i++)
  {
    if(a[i]==x&&b[i]>y)
    {
      if(b[i]<mn)mn=b[i],f=c[i];
    }
  }
  if(f=='R'||f=='Q')yes();
   mn=-(2e9+1);f='a';
  for(int i=1;i<=n;i++)
  {
    if(a[i]==x&&b[i]<y)
    {
      if(b[i]>mn)mn=b[i],f=c[i];
    }
  }
  if(f=='R'||f=='Q')yes();
   mn=2e9+1;f='a';
  for(int i=1;i<=n;i++)
  {
    if(b[i]==y&&a[i]>x)
    {
      if(a[i]<mn)mn=a[i],f=c[i];
    }
  }
  if(f=='R'||f=='Q')yes();
   mn=-(2e9+1);f='a';
  for(int i=1;i<=n;i++)
  {
    if(b[i]==y&&a[i]<x)
    {
      if(a[i]>mn)mn=a[i],f=c[i];
    }
  }
  if(f=='R'||f=='Q')yes();
      mn=2e9+1;f='a';
  for(int i=1;i<=n;i++)
  {
    if(a[i]+b[i]==x+y&&b[i]>y)
    {
      if(b[i]<mn)mn=b[i],f=c[i];
    }
  }
  if(f=='B'||f=='Q')yes();
   mn=2e9+1;f='a';
  for(int i=1;i<=n;i++)
  {
    if(a[i]+b[i]==x+y&&a[i]>x)
    {
      if(a[i]<mn)mn=a[i],f=c[i];
    }
  }
  if(f=='B'||f=='Q')yes();
   mn=2e9+1;f='a';
  for(int i=1;i<=n;i++)
  {
    if(a[i]-b[i]==x-y&&b[i]>y)
    {
      if(b[i]<mn)mn=b[i],f=c[i];
    }
  }
  if(f=='B'||f=='Q')yes();
   mn=2e9+1;f='a';
  for(int i=1;i<=n;i++)
  {
    if(a[i]-b[i]==x-y&&a[i]>x)
    {
      if(a[i]<mn)mn=a[i],f=c[i];
    }
  }
  if(f=='B'||f=='Q')yes();
  cout<<"NO"<<endl;
   return 0;
}