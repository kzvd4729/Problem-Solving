/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/24/2020 22:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 233 ms                                          memory_used: 35200 KB                             
*  problem: https://codeforces.com/contest/1454/problem/F
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
const int N=2e5;
int mn[N+2][20+2],mx[N+2][20+2],a[N+2];
void build(int n)
{
  for(int i=1;i<=n;i++)mn[i][0]=a[i];
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      mn[i][j]=mn[i][j-1];
      if((i+(1<<(j-1)))<=n)
        mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
    }
  }
}
int getMin(int lt,int rt)
{
  //if(rt<lt)return 1e9;
  int dg=31-__builtin_clz(rt-lt+1);
  return min(mn[lt][dg],mn[rt-(1<<dg)+1][dg]);
}
void build2(int n)
{
  for(int i=1;i<=n;i++)mx[i][0]=a[i];
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      mx[i][j]=mx[i][j-1];
      if((i+(1<<(j-1)))<=n)
        mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
    }
  }
}
int getMax(int lt,int rt)
{
  //if(rt<lt)return 1e9;
  int dg=31-__builtin_clz(rt-lt+1);
  return max(mx[lt][dg],mx[rt-(1<<dg)+1][dg]);
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(n);build2(n);
     int mx=0,x=-1,z;
    for(int i=1;i<=n-1;i++)
    {
      mx=max(mx,a[i]);
       int lo=i+1,hi=n,md;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(getMin(i+1,md)>mx)lo=md;
        else hi=md;
      }
      for(md=lo;md<=hi;md++)
      {
        if(getMin(i+1,md)<=mx)break;
      }
      if(md>=n)continue;
      if(getMin(i+1,md)!=mx)continue;
       int l1=md;
       lo=i+1,hi=n,md;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(getMin(i+1,md)>=mx)lo=md;
        else hi=md;
      }
      for(md=lo;md<=hi;md++)
      {
        if(getMin(i+1,md)<mx)break;
      }
      int r1=md-1;if(r1==n)r1--;
        lo=l1+1,hi=r1+1;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        if(getMax(md,n)>mx)lo=md;
        else hi=md;
      }
      for(md=lo;md<=hi;md++)
        if(getMax(md,n)==mx)x=i,z=n-md+1;
    }
    if(x==-1)cout<<"NO\n";
    else cout<<"YES\n"<<x<<" "<<n-x-z<<" "<<z<<'\n';
  }
  return 0;
}