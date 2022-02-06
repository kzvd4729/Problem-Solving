/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/26/2018 04:06                        
*  solution_verdict: Memory limit exceeded on test 1         language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 524300 KB                            
*  problem: https://codeforces.com/contest/707/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int n,m,q,nw,rt[N+2];
struct persistent
{
  int l,r,sm,lz;
}seg[34*N*N];
void too_lazy(int node,int pnode,int lo,int hi)
{
  seg[node].lz^=seg[pnode].lz;
  if(seg[node].lz)seg[node].sm=hi-lo+1-seg[pnode].sm;
  else seg[node].sm=seg[pnode].sm;
  seg[node].l=++nw;seg[node].r=++nw;
   seg[seg[node].l].lz=seg[node].lz;
  seg[seg[node].r].lz=seg[node].lz;
  seg[node].lz=0;
}
void upd(int node,int lo,int hi,int pnode,int lt,int rt)
{
  too_lazy(node,pnode,lo,hi);
  if(lo>rt||hi<lt)
  {
    int lazy=seg[seg[node].l].lz;
    seg[seg[node].l]=seg[seg[pnode].l];
    seg[seg[node].l].lz^=lazy;
     lazy=seg[seg[node].r].lz;
    seg[seg[node].r]=seg[seg[pnode].r];
    seg[seg[node].r].lz^=lazy;
    return ;
  }
  if(lo>=lt&&hi<=rt)
  {
    //cout<<lo<<"---"<<hi<<"---"<<seg[node].sm<<endl;
    seg[node].sm=hi-lo+1-seg[node].sm;
    seg[seg[node].l].lz^=1;seg[seg[node].r].lz^=1;
     int lazy=seg[seg[node].l].lz;
    seg[seg[node].l]=seg[seg[pnode].l];
    seg[seg[node].l].lz^=lazy;
     lazy=seg[seg[node].r].lz;
    seg[seg[node].r]=seg[seg[pnode].r];
    seg[seg[node].r].lz^=lazy;
     return ;
  }
  int md=(lo+hi)/2;
  upd(seg[node].l,lo,md,seg[pnode].l,lt,rt);
  upd(seg[node].r,md+1,hi,seg[pnode].r,lt,rt);
  seg[node].sm=seg[seg[node].l].sm+seg[seg[node].r].sm;
}
void upd1(int node,int lo,int hi,int pnode,int id,int vl)
{
  too_lazy(node,pnode,lo,hi);
  if(lo>id||hi<id)
  {
    int lazy=seg[seg[node].l].lz;
    seg[seg[node].l]=seg[seg[pnode].l];
    seg[seg[node].l].lz^=lazy;
     lazy=seg[seg[node].r].lz;
    seg[seg[node].r]=seg[seg[pnode].r];
    seg[seg[node].r].lz^=lazy;
    return ;
  }
  if(lo==hi)
  {
    seg[node].sm=vl;
    return ;
  }
  int md=(lo+hi)/2;
  upd1(seg[node].l,lo,md,seg[pnode].l,id,vl);
  upd1(seg[node].r,md+1,hi,seg[pnode].r,id,vl);
  seg[node].sm=seg[seg[node].l].sm+seg[seg[node].r].sm;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int pre=0;cin>>n>>m>>q;
  for(int i=1;i<=q;i++)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int ii,jj;cin>>ii>>jj;
      int id=(ii-1)*m+jj;rt[i]=++nw;
      upd1(rt[i],1,n*m,pre,id,1);
    }
    else if(ty==2)
    {
      int ii,jj;cin>>ii>>jj;
      int id=(ii-1)*m+jj;rt[i]=++nw;
      upd1(rt[i],1,n*m,pre,id,0);
    }
    else if(ty==3)
    {
      int ii;cin>>ii;rt[i]=++nw;
      upd(rt[i],1,n*m,pre,(ii-1)*m+1,ii*m);
    }
    else
    {
      int k;cin>>k;rt[i]=rt[k];
    }
    cout<<seg[rt[i]].sm<<"\n";
    pre=rt[i];
  }
  return 0;
}