/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/09/2020 16:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 608 ms                                          memory_used: 85600 KB                             
*  problem: https://codeforces.com/contest/746/problem/F
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
#include<deque>
#define long long long
using namespace std;
const int N=2e5;
struct persistent
{
  int l,r,sm,cn,od;
}seg[N*20+2];
int rot[N+2],nw;
void upd(int node,int pnode,int lo,int hi,int id,int vl)
{
  if(lo==hi)
  {
    seg[node].sm=seg[pnode].sm+vl;seg[node].cn=seg[pnode].cn+1;
    seg[node].od=seg[pnode].od+vl%2;return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)
  {
    if(!seg[node].l)seg[node].l=++nw;upd(seg[node].l,seg[pnode].l,lo,md,id,vl);
    seg[node].r=seg[pnode].r;
  }
  else
  {
    if(!seg[node].r)seg[node].r=++nw;upd(seg[node].r,seg[pnode].r,md+1,hi,id,vl);
    seg[node].l=seg[pnode].l;
  }
  seg[node].sm=seg[seg[node].l].sm+seg[seg[node].r].sm;
  seg[node].cn=seg[seg[node].l].cn+seg[seg[node].r].cn;
  seg[node].od=seg[seg[node].l].od+seg[seg[node].r].od;
}
pair<int,int>get(int node,int pnode,int lo,int hi,int k)
{
  if(lo==hi)
  {
    assert(k==1);return {seg[node].sm-seg[pnode].sm,seg[node].od-seg[pnode].od};
  }
  int md=(lo+hi)/2;
  int rm=seg[seg[node].l].cn-seg[seg[pnode].l].cn;
  if(rm>=k)return get(seg[node].l,seg[pnode].l,lo,md,k);
  else 
  {
    pair<int,int>p=get(seg[node].r,seg[pnode].r,md+1,hi,k-rm);
    return {p.first+seg[seg[node].l].sm-seg[seg[pnode].l].sm,p.second+seg[seg[node].l].od-seg[seg[pnode].l].od};
  }
}
int a[N+2],t[N+2],id[N+2];
int qm[N+2],od[N+2],w,k,n;
pair<int,int>p[N+2];
bool ok(int i,int j)
{
  long tt=0;int s=qm[j-1]-qm[i-1],o=od[j-1]-od[i-1];
  if(j-i<=w)return (s+o)/2<=k;
  int rm=(j-i)-w;
  pair<int,int>p=get(rot[i],rot[j],1,n,rm);
  s-=p.first,o-=p.second;
  return p.first+(s+o)/2<=k;
}
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>w>>k;
  for(int i=1;i<=n;i++)cin>>a[i],aa[i]=aa[i-1]+a[i];
  for(int i=1;i<=n;i++)cin>>t[i],p[i]={t[i],i};
  for(int i=1;i<=n;i++)
  {
    qm[i]=qm[i-1]+t[i];
    od[i]=od[i-1]+t[i]%2;
  }
  sort(p+1,p+n+1);
  for(int i=1;i<=n;i++)id[p[i].second]=i;
  int ans=0;
  for(int i=n;i>=1;i--)
  {
    rot[i]=++nw;upd(rot[i],rot[i+1],1,n,id[i],t[i]);
    if((t[i]+1)/2>k)continue;
    int lo=i,hi=n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(ok(i,md+1))lo=md;
      else hi=md;
    }
    for(md=hi;md>=lo;md--)if(ok(i,md+1))break;
    ans=max(ans,aa[md]-aa[i-1]);
  }
  cout<<ans<<endl;
  return 0;
}