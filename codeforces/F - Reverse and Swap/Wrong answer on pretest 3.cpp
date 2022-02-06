/****************************************************************************************
*  @author: * kzvd4729                                       created: Aug/21/2020 22:08                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 119900 KB                            
*  problem: https://codeforces.com/contest/1401/problem/F
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
#include<unordered_set>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=(1<<18),inf=1e9;
int bit[18+2][N+2],nn;
bool sg[18+2][8*N+8],lz[18+2][8*N+8];
void tooLazy(int id,int node,int lo,int hi)
{
  if(!lz[id][node])return;
  if(lo==hi)sg[id][node]^=1;
  else lz[id][node*2]^=1,lz[id][node*2+1]^=1;
  lz[id][node]=0;
}
void upd(int id,int node,int lo,int hi,int lt,int rt)
{
  tooLazy(id,node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lz[id][node]^=1;tooLazy(id,node,lo,hi);return;
  }
  int md=(lo+hi)/2;
  upd(id,node*2,lo,md,lt,rt);upd(id,node*2+1,md+1,hi,lt,rt);
}
int get(int id,int node,int lo,int hi,int ind)
{
  tooLazy(id,node,lo,hi);
  if(lo==hi)return sg[id][node];
  int md=(lo+hi)/2;
  if(ind<=md)return get(id,node*2,lo,md,ind);
  else return get(id,node*2+1,md+1,hi,ind);
}
int sz=1,a[N+2];
struct segment
{
  int l,r,sz;
  vector<long>bit;
  void add(int x,int vl)
  {
    for( ;x<=sz;x+=x&-x)bit[x]+=vl;
  }
  long get(int x)
  {
    long ret=0;
    for( ;x>0;x-=x&-x)ret+=bit[x];
    return ret;
  }
}seg[2*N+8];
void build(int node,int lo,int hi)
{
  seg[node].sz=hi-lo+1;seg[node].bit.resize(hi-lo+1+2);
  for(int i=lo;i<=hi;i++)seg[node].add(i-lo+1,a[i]);
   if(lo==hi)return;
  seg[node].l=++sz;seg[node].r=++sz;
  int md=(lo+hi)/2;
  build(seg[node].l,lo,md);build(seg[node].r,md+1,hi);
}
void rep(int l,int node,int lo,int hi,int id,int vl)
{
  if(get(l,1,1,2*nn,node))
  {
    swap(seg[node].l,seg[node].r);
    upd(l,1,1,2*nn,node,node);
  }
  int pr=seg[node].get(id-lo+1)-seg[node].get(id-lo);
  seg[node].add(id-lo+1,vl-pr);
   if(lo==hi)return;int md=(lo+hi)/2;
  if(id<=md)rep(l+1,seg[node].l,lo,md,id,vl);
  else rep(l+1,seg[node].r,md+1,hi,id,vl);
}
long sm(int l,int node,int lo,int hi,int lt,int rt)
{
  if(get(l,1,1,2*nn,node))
  {
    swap(seg[node].l,seg[node].r);
    upd(l,1,1,2*nn,node,node);
  }
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node].get(hi-lo+1);
  int md=(lo+hi)/2;
  return sm(l+1,seg[node].l,lo,md,lt,rt)+sm(l+1,seg[node].r,md+1,hi,lt,rt);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;nn=(1<<n);
   for(int i=1;i<=nn;i++)cin>>a[i];
  build(1,1,nn);
   while(q--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int x,k;cin>>x>>k;
      rep(0,1,1,nn,x,k);
    }
    else if(ty==2)
    {
      int k;cin>>k;
      for(int i=n-k;i<n;i++)upd(i,1,1,2*nn,1,2*nn);
    }
    else if(ty==3)
    {
      int k;cin>>k;
      upd(n-k-1,1,1,2*nn,1,2*nn);
    }
    else
    {
      int l,r;cin>>l>>r;
      cout<<sm(0,1,1,nn,l,r)<<'\n';
    }
  }
  return 0;
}