/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/05/2020 00:03                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 52500 KB                             
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
int a[N+2];
int sz;
struct segment
{
  int l,r,sm;
}seg[42*N+2];//2*lg(mx)*N
void upd(int node,int lo,int hi,int pnode,int id,int vl)
{
  if(lo==hi){seg[node].sm=(1LL*seg[pnode].sm*vl)%mod;return ;}
  int md=(lo+hi)/2;
  if(id<=md)
  {
    seg[node].l=++sz;seg[sz].sm=1;
    upd(seg[node].l,lo,md,seg[pnode].l,id,vl);
    seg[node].r=seg[pnode].r;
  }
  else
  {
    seg[node].r=++sz;seg[sz].sm=1;
    upd(seg[node].r,md+1,hi,seg[pnode].r,id,vl);
    seg[node].l=seg[pnode].l;
  }
  seg[node].sm=(1LL*seg[seg[node].l].sm*seg[seg[node].r].sm)%mod;
}
int get(int node,int lo,int hi,int lt,int rt)
{
  if(lo>=lt&&hi<=rt)return seg[node].sm;
  if(lo>rt||hi<lt)return 1;
  int md=(lo+hi)/2;
  return (1LL*get(seg[node].l,lo,md,lt,rt)*get(seg[node].r,md+1,hi,lt,rt))%mod;
}
int sg[4*N+8];
void build(int nd,int lo,int hi)
{
  if(lo==hi){sg[nd]=a[lo];return ;}
  int md=(lo+hi)/2;
  build(nd*2,lo,md);build(nd*2+1,md+1,hi);
  sg[nd]=__gcd(sg[nd*2],sg[nd*2+1]);
}
int gt(int nd,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return sg[nd];
  int md=(lo+hi)/2;
  return __gcd(gt(nd*2,lo,md,lt,rt),gt(nd*2+1,md+1,hi,lt,rt));
}
int last[N+2],root[N+2];
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
void solve(int n,int mx)
{
  for(int i=1;i<=n;i++)
  {
    int x;x=a[i];int tmp=++sz;seg[sz].sm=1;
    upd(tmp,1,mx,root[i-1],i,x);
    if(last[x]){root[i]=++sz;seg[sz].sm=1;upd(root[i],1,mx,tmp,last[x],big(x,mod-2));}
    else root[i]=tmp;
        last[x]=i;
  }
  //cout<<get(root[right],1,N,left,right)<<"\n";
}
int ml[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;seg[0].sm=1;
  for(int i=1;i<=n;i++)cin>>a[i];
  solve(n,n);build(1,1,n);
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
      //int al=(1LL*ml[y]*big(ml[x-1],mod-2))%mod;
      int al=get(root[y],1,n,x,y);
      int gc=gt(1,1,n,x,y);
      ls=(1LL*al*big(gc,mod-2))%mod;
    }
    cout<<ls<<'\n';
  }
    return 0;
}