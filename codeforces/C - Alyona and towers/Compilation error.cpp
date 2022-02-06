/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/10/2019 16:18                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/739/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int lft[N+2],rgt[N+2],aa[N+2];
struct segment
{
  long sum;
  int l,r,mx,lz,ll,lr;
}seg[N*5+2];
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[node]={aa[lo],lft[lo],rgt[lo],lft[lo]+rgt[lo],0,0,0};
    return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);
  build(node*2+1,md+1,hi);
   seg[node].sum=seg[node*2].sum+seg[node*2+1].sum;
  seg[node].l=max(seg[node*2].l,seg[node*2+1].l);
  seg[node].r=max(seg[node*2].r,seg[node*2+1].r);
  seg[node].mx=max(seg[node*2].mx,seg[node*2+1].mx);
}
void too_lazy_vl(int node,int lo,int hi)
{
  seg[node].sum+=((hi-lo+1)*1LL)*seg[node].lz;
  if(lo!=hi)
  {
    seg[node*2].lz+=seg[node].lz;
    seg[node*2+1].lz+=seg[node].lz;
  }
  seg[node].lz=0;
}
void upd_vl(int node,int lo,int hi,int lt,int rt,int vl)
{
  too_lazy_vl(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    seg[node].lz+=vl;
    too_lazy_vl(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd_vl(node*2,lo,md,lt,rt,vl);
  upd_vl(node*2+1,md+1,hi,lt,rt,vl);
  seg[node].sum=seg[node*2].sum+seg[node*2+1].sum;
}
void too_lazy_lt(int node,int lo,int hi)
{
  seg[node].l+=seg[node].ll;
  seg[node].mx+=seg[node].ll;
  if(lo!=hi)
  {
    seg[node*2].ll+=seg[node].ll;
    seg[node*2+1].ll+=seg[node].ll;
  }
  seg[node].ll=0;
}
void upd_lt(int node,int lo,int hi,int lt,int rt,int vl)
{
  too_lazy_lt(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    seg[node].ll+=vl;
    too_lazy_lt(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd_lt(node*2,lo,md,lt,rt,vl);
  upd_lt(node*2+1,md+1,hi,lt,rt,vl);
  seg[node].l=max(seg[node*2].l,seg[node*2+1].l);
  seg[node].mx=max(seg[node*2].mx,seg[node*2+1].mx);
}
void too_lazy_rt(int node,int lo,int hi)
{
  seg[node].r+=seg[node].lr;
  seg[node].mx+=seg[node].lr;
  if(lo!=hi)
  {
    seg[node*2].lr+=seg[node].lr;
    seg[node*2+1].lr+=seg[node].lr;
  }
  seg[node].lr=0;
}
void upd_rt(int node,int lo,int hi,int lt,int rt,int vl)
{
  too_lazy_rt(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    seg[node].lr+=vl;
    too_lazy_rt(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd_rt(node*2,lo,md,lt,rt,vl);
  upd_rt(node*2+1,md+1,hi,lt,rt,vl);
  seg[node].r=max(seg[node*2].r,seg[node*2+1].r);
  seg[node].mx=max(seg[node*2].mx,seg[node*2+1].mx);
}
int qry_vl(int node,int lo,int hi,int id)
{
  too_lazy_vl(node,lo,hi);
  if(lo==hi)return seg[node].sum;
  int md=(lo+hi)/2;
  if(id<=md)return qry_vl(node*2,lo,md,id);
  else return qry_vl(node*2+1,md+1,hi,id);
}
int qry_lt(int node,int lo,int hi,int id)
{
  too_lazy_lt(node,lo,hi);
  if(lo==hi)return seg[node].l;
  int md=(lo+hi)/2;
  if(id<=md)return qry_lt(node*2,lo,md,id);
  else return qry_lt(node*2+1,md+1,hi,id);
}
int qry_rt(int node,int lo,int hi,int id)
{
  too_lazy_rt(node,lo,hi);
  if(lo==hi)return seg[node].r;
  int md=(lo+hi)/2;
  if(id<=md)return qry_rt(node*2,lo,md,id);
  else return qry_rt(node*2+1,md+1,hi,id);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=2;i<=n;i++)
    if(aa[i]>aa[i-1])lft[i]=lft[i-1]+1;
  for(int i=n-1;i>=1;i--)
    if(aa[i]>aa[i+1])rgt[i]=rgt[i+1]+1;
  build(1,1,n);
  int q;cin>>q;
  while(q--)
  {
    int lt,rt,vl;cin>>lt>>rt>>vl;
    upd_vl(1,1,n,lt,rt,vl);
     while(true)
    {
      if(lt==1)break;
      int a=qry_vl(1,1,n,lt-1);
      int b=qry_vl(1,1,n,lt);
      if(b-vl>a||b<a)break;
       int inc=qry_rt(1,1,n,lt);
      int rn=qry_lt(1,1,n,lt-1);
       upd_rt(1,1,n,lt-1-rn,lt-1,inc+1);
      upd_lt(1,1,n,lt,lt+inc,rn+1);
       Do not compile
       break;
    }
     while(true)
    {
      if(rt==n)break;
      int a=qry_vl(1,1,n,rt+1);
      int b=qry_vl(1,1,n,rt);
      if(b-vl>a||b<a)break;
       int inc=qry_rt(1,1,n,lt);
      int rn=qry_lt(1,1,n,lt-1);
       upd_rt(1,1,n,lt-1-rn,lt-1,inc+1);
      upd_lt(1,1,n,lt,lt+inc,rn+1);
      break;
    }
   }
  return 0;
}