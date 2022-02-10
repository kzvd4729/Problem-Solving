/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-26 23:24:47                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 750                                        memory_used (MB): 423.9                           
*  problem: https://vjudge.net/problem/SPOJ-TTM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long arr[N+2],n,rt[N+2],nw;
struct persistent
{
  long l,r,sm,lz;
}seg[130*N];
void build(long node,long lo,long hi)
{
  if(lo==hi)
  {
    seg[node].sm=arr[lo];return ;
  }
  long md=(lo+hi)/2;
  seg[node].l=++nw;seg[node].r=++nw;
  build(seg[node].l,lo,md);build(seg[node].r,md+1,hi);
  seg[node].sm=seg[seg[node].l].sm+seg[seg[node].r].sm;
}
void too_lazy(long node,long pnode,long lo,long hi)
{
  seg[node].lz+=seg[pnode].lz;
  seg[node].sm=seg[pnode].sm+(hi-lo+1)*seg[node].lz;

  seg[node].l=++nw;seg[node].r=++nw;
  seg[seg[node].l].lz=seg[node].lz;
  seg[seg[node].r].lz=seg[node].lz;
  seg[node].lz=0;
}
void make_link(long node,long pnode)
{
  long lazy=seg[seg[node].l].lz;
  seg[seg[node].l]=seg[seg[pnode].l];
  seg[seg[node].l].lz+=lazy;

  lazy=seg[seg[node].r].lz;
  seg[seg[node].r]=seg[seg[pnode].r];
  seg[seg[node].r].lz+=lazy;
}
void upd(long node,long lo,long hi,long pnode,long lt,long rt,long vl)
{
  too_lazy(node,pnode,lo,hi);
  if(lo>rt||hi<lt)
  {
    make_link(node,pnode);return ;
  }
  if(lo>=lt&&hi<=rt)
  {
    seg[node].sm+=(hi-lo+1)*vl;
    seg[seg[node].l].lz+=vl;seg[seg[node].r].lz+=vl;
    make_link(node,pnode);
    return ;
  }
  long md=(lo+hi)/2;
  upd(seg[node].l,lo,md,seg[pnode].l,lt,rt,vl);
  upd(seg[node].r,md+1,hi,seg[pnode].r,lt,rt,vl);
  seg[node].sm=seg[seg[node].l].sm+seg[seg[node].r].sm;
}
long qry(long node,long lo,long hi,long pnode,long lt,long rt)
{
  too_lazy(node,pnode,lo,hi);
  if(lo>rt||hi<lt)
  {
    make_link(node,pnode);return 0;
  }
  if(lo>=lt&&hi<=rt)
  {
    make_link(node,pnode);
    return seg[node].sm;
  }
  long md=(lo+hi)/2;
  long p1=qry(seg[node].l,lo,md,seg[pnode].l,lt,rt);
  long p2=qry(seg[node].r,md+1,hi,seg[pnode].r,lt,rt);
  return p1+p2;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long q;cin>>n>>q;
  for(long i=1;i<=n;i++)cin>>arr[i];
  rt[0]=++nw;build(rt[0],1,n);long now=0;
  while(q--)
  {
    char ch;cin>>ch;
    if(ch=='C')
    {
      long l,r,vl;cin>>l>>r>>vl;
      rt[++now]=++nw;
      upd(rt[now],1,n,rt[now-1],l,r,vl);
    }
    else if(ch=='Q')
    {
      long l,r;cin>>l>>r;
      cout<<qry(++nw,1,n,rt[now],l,r)<<endl;
    }
    else if(ch=='H')
    {
      long l,r,t;cin>>l>>r>>t;
      cout<<qry(++nw,1,n,rt[t],l,r)<<endl;
    }
    else
    {
      long t;cin>>t;
      rt[now]=rt[t];now=t;
    }
  }
  return 0;
}