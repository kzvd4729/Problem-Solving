/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/04/2020 23:52                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 2400 KB                              
*  problem: https://codeforces.com/contest/1422/problem/F
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
const int N=1e5,mod=1e9+7;
int seg[4*N+8],a[N+2];
void build(int nd,int lo,int hi)
{
  if(lo==hi){seg[nd]=a[lo];return ;}
  int md=(lo+hi)/2;
  build(nd*2,lo,md);build(nd*2+1,md+1,hi);
  seg[nd]=__gcd(seg[nd*2],seg[nd*2+1]);
}
int get(int nd,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[nd];
  int md=(lo+hi)/2;
  return __gcd(get(nd*2,lo,md,lt,rt),get(nd*2+1,md+1,hi,lt,rt));
}
int ml[N+2];
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  build(1,1,n);
   ml[0]=1;
  for(int i=1;i<=n;i++)ml[i]=(1LL*ml[i-1]*a[i])%mod;
   int ls=0;int q;cin>>q;
  while(q--)
  {
    int x,y;cin>>x>>y;
    x=(x+ls)%n+1,y=(y+ls)%n+1;
     if(x>y)swap(x,y);assert(x>0);
    if(x==y)ls=a[x];
    else
    {
      int al=(1LL*ml[y]*big(ml[x-1],mod-2))%mod;
      int gc=get(1,1,n,x,y);
      ls=(1LL*al*big(gc,mod-2))%mod;
    }
    cout<<ls<<'\n';
  }
    return 0;
}