/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/25/2018 16:01                        
*  solution_verdict: Wrong answer on test 17                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 516900 KB                            
*  problem: https://codeforces.com/contest/707/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int sz,rt[N+2];
struct persistent
{
  int l,r,lz,sm;
}seg[33*N*N];
void too_lazy(int node,int lo,int hi)
{
  //cout<<"lz  "<<seg[node].lz<<endl;
  if(lo!=hi)
  {
    if(!seg[node].l)seg[node].l=++sz;
    if(!seg[node].r)seg[node].r=++sz;
  }
  if(seg[node].lz)
  {
    seg[node].sm=hi-lo+1-seg[node].sm;
    if(lo!=hi)
    {
      seg[seg[node].l].lz^=seg[node].lz;
      seg[seg[node].r].lz^=seg[node].lz;
    }
  }
  seg[node].lz=0;
}
void upd(int node,int lo,int hi,int pnode,int lt,int rt)
{
  too_lazy(pnode,lo,hi);
  if(lo>rt||hi<lt)
  {
    seg[node]=seg[pnode];
    return ;
  }
  if(lo!=hi)
  {
    if(!seg[node].l)seg[node].l=++sz;
    if(!seg[node].r)seg[node].r=++sz;
  }
  int md=(lo+hi)/2;
  if(lo>=lt&&hi<=rt)
  {
    seg[node].sm=hi-lo+1-seg[pnode].sm;
    if(lo!=hi)
    {
      too_lazy(seg[pnode].l,lo,md);
      too_lazy(seg[pnode].r,md+1,hi);
      seg[node].l=seg[pnode].l;
      seg[node].r=seg[pnode].r;
      //cout<<seg[node].l<<"-------"<<seg[node].r<<endl;
      seg[seg[node].l].lz^=1;
      seg[seg[node].r].lz^=1;
    }
    return ;
  }
  upd(seg[node].l,lo,md,seg[pnode].l,lt,rt);
  upd(seg[node].r,md+1,hi,seg[pnode].r,lt,rt);
  seg[node].sm=seg[seg[node].l].sm+seg[seg[node].r].sm;
}
void upd1(int node,int lo,int hi,int pnode,int id,int vl)
{
  too_lazy(pnode,lo,hi);
  if(lo==hi)
  {
    seg[node].sm=vl;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)
  {
    if(!seg[node].l)seg[node].l=++sz;
    upd1(seg[node].l,lo,md,seg[pnode].l,id,vl);
    too_lazy(seg[pnode].r,md+1,hi);
    seg[node].r=seg[pnode].r;
    //cout<<"----------- "<<seg[pnode].r<<" "<<seg[seg[pnode].r].sm<<endl;
  }
  else
  {
    if(!seg[node].r)seg[node].r=++sz;
    upd1(seg[node].r,md+1,hi,seg[pnode].r,id,vl);
    too_lazy(seg[pnode].l,lo,md);
    seg[node].l=seg[pnode].l;
    //cout<<"----------- "<<seg[pnode].l<<" "<<seg[seg[pnode].l].sm<<endl;
   }
  seg[node].sm=seg[seg[node].l].sm+seg[seg[node].r].sm;
  //cout<<"--------"<<seg[node].sm<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,q;cin>>n>>m>>q;
  for(int i=1;i<=q;i++)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int ii,jj;cin>>ii>>jj;
      int id=(ii-1)*m+jj;rt[i]=++sz;
      upd1(rt[i],1,n*m,rt[i-1],id,1);
    }
    else if(ty==2)
    {
      int ii,jj;cin>>ii>>jj;
      int id=(ii-1)*m+jj;rt[i]=++sz;
      upd1(rt[i],1,n*m,rt[i-1],id,0);
    }
    else if(ty==3)
    {
      int ii;cin>>ii;rt[i]=++sz;
      upd(rt[i],1,n*m,rt[i-1],(ii-1)*m+1,ii*m);
    }
    else
    {
      int k;cin>>k;rt[i]=rt[k];
    }
    //cout<<"sz "<<sz<<endl;
    cout<<seg[rt[i]].sm<<endl;
  }
  return 0;
}