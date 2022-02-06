/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/05/2019 23:19                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++14                               
*  run_time: 217 ms                                          memory_used: 37600 KB                             
*  problem: https://codeforces.com/contest/1132/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long aa[N+2],bb[N+2],cc[N+2],lazy[5*N+2],ex[N+2];
struct segment
{
  long lf,ex,id;
}seg[5*N+2];
void too_lazy(long node,long lo,long hi)
{
  seg[node].lf+=lazy[node];
  if(lo!=hi)
  {
    lazy[node*2]+=lazy[node];
    lazy[node*2+1]+=lazy[node];
  }
  lazy[node]=0;
}
void build(long node,long lo,long hi)
{
  if(lo==hi)
  {
    seg[node]={cc[lo],ex[lo],lo};return ;
  }
  long md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  if(seg[node*2].lf<=seg[node*2+1].lf)
    seg[node]=seg[node*2];
  else seg[node]=seg[node*2+1];
}
void upd1(long node,long lo,long hi,long lt,long rt)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lazy[node]--;too_lazy(node,lo,hi);
    return ;
  }
  long md=(lo+hi)/2;
  upd1(node*2,lo,md,lt,rt);
  upd1(node*2+1,md+1,hi,lt,rt);
  if(seg[node*2].lf<=seg[node*2+1].lf)
    seg[node]=seg[node*2];
  else seg[node]=seg[node*2+1];
}
void upd2(long node,long lo,long hi,long id,long vl,long ex)
{
  too_lazy(node,lo,hi);
  if(lo>id||hi<id)return ;
  if(lo>=id&&hi<=id)
  {
    seg[node].lf=vl;seg[node].ex=ex;
    return ;
  }
  long md=(lo+hi)/2;
  upd2(node*2,lo,md,id,vl,ex);
  upd2(node*2+1,md+1,hi,id,vl,ex);
  if(seg[node*2].lf<=seg[node*2+1].lf)
    seg[node]=seg[node*2];
  else seg[node]=seg[node*2+1];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,k;cin>>n>>k;
  for(long i=1;i<=n;i++)
    cin>>aa[i];
  for(long i=1;i<=n;i++)
    cin>>bb[i];
  for(long i=1;i<=n;i++)
  {
    cc[i]=aa[i]/bb[i];
    ex[i]=aa[i]%bb[i];
  }
  long lo=0,hi=2e15+2,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;build(1,1,n);
    long f=0;
    for(long i=1;i<k;i++)
    {
      upd1(1,1,n,1,n);segment sg=seg[1];
      sg.lf+=md/bb[sg.id];sg.ex+=md%bb[sg.id];
      if(sg.ex>=bb[sg.id])sg.lf++,sg.ex-=bb[sg.id];
      upd2(1,1,n,sg.id,sg.lf,sg.ex);
      if(seg[1].lf<0)
      {
        f=1;break;
      }
    }
    if(f)lo=md;else hi=md;
  }
  for(md=lo;md<=hi;md++)
  {
    build(1,1,n);long f=0;
    for(long i=1;i<k;i++)
    {
      upd1(1,1,n,1,n);segment sg=seg[1];
      sg.lf+=md/bb[sg.id];sg.ex+=md%bb[sg.id];
      if(sg.ex>=bb[sg.id])sg.lf++,sg.ex-=bb[sg.id];
      upd2(1,1,n,sg.id,sg.lf,sg.ex);
      if(seg[1].lf<0)
      {
        f=1;break;
      }
    }
    if(!f)cout<<md<<endl,exit(0);
  }
  cout<<-1<<endl;
  return 0;
}