/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/25/2019 22:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 561 ms                                          memory_used: 17200 KB                             
*  problem: https://codeforces.com/contest/1208/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
const long inf=1e18;
long seg[5*N+2],aa[N+2],lazy[5*N+2];
void too_lazy(long node,long lo,long hi)
{
  seg[node]+=lazy[node];
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
    seg[node]=aa[lo];
    return ;
  }
  long md=(lo+hi)/2;
  build(node*2,lo,md);
  build(node*2+1,md+1,hi);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
void upd(long node,long lo,long hi,long lt,long rt,long vl)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lazy[node]+=vl;too_lazy(node,lo,hi);
    return ;
  }
  long md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl);
  upd(node*2+1,md+1,hi,lt,rt,vl);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
long get(long node,long lo,long hi)
{
  too_lazy(node,lo,hi);
  if(lo==hi)
  {
    //cout<<lo<<" -- "<<seg[node]<<endl;
    return lo;
  }
  long md=(lo+hi)/2;
  too_lazy(node*2,lo,md);too_lazy(node*2+1,md+1,hi);
  if(!seg[node*2+1])return get(node*2+1,md+1,hi);
  else return get(node*2,lo,md);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=1;i<=n;i++)cin>>aa[i];
  build(1,1,n);
   for(long i=1;i<=n;i++)
  {
    long id=get(1,1,n);
    //cout<<"id "<<id<<endl;
    aa[id]=i;
    upd(1,1,n,id,n,-i);
    upd(1,1,n,id,id,inf);
  }
  for(long i=1;i<=n;i++)
    cout<<aa[i]<<" ";
  cout<<endl;
  return 0;
}