/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-14 16:36:13                      
*  solution_verdict: Wrong answer #0                         language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-GSS3
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2];
struct segment
{
  int lt,rt,mx,sm;
}seg[5*N+2];
void mrge(segment &p,segment &p1,segment &p2)
{
  p.sm=p1.sm+p2.sm;
  p.lt=max(p1.lt,p1.sm+p2.lt);
  p.rt=max(p2.rt,p1.rt+p2.sm);
  p.mx=max(max(p1.mx,p2.mx),p1.rt+p2.lt);
}
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[node]={aa[lo],aa[lo],aa[lo],aa[lo]};return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  mrge(seg[node],seg[node*2],seg[node*2+1]);
}
void upd(int node,int lo,int hi,int id,int vl)
{
  if(lo==hi)
  {
    seg[node]={vl,vl,vl,vl};return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);
  mrge(seg[node],seg[node*2],seg[node*2+1]); 
}
segment get(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return {-inf,-inf,-inf,-inf};
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;segment p,p1,p2;
  p1=get(node*2,lo,md,lt,rt),p2=get(node*2+1,md+1,hi,lt,rt);
  mrge(p,p1,p2);return p;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;for(int i=1;i<=n;i++)cin>>aa[i];
  build(1,1,n);int q;cin>>q;
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==0)
    {
      int id,vl;cin>>id>>vl;upd(1,1,n,id,vl);
    }
    else
    {
      int lt,rt;cin>>lt>>rt;
      cout<<get(1,1,n,lt,rt).mx<<"\n";
    }
  }
  return 0;
}