/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/25/2019 22:05                        
*  solution_verdict: Wrong answer on pretest 9               language: GNU C++14                               
*  run_time: 108 ms                                          memory_used: 8600 KB                              
*  problem: https://codeforces.com/contest/1208/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int seg[5*N+2],aa[N+2],lazy[5*N+2];
void too_lazy(int node,int lo,int hi)
{
  seg[node]+=lazy[node];
  if(lo!=hi)
  {
    lazy[node*2]+=lazy[node];
    lazy[node*2+1]+=lazy[node];
  }
  lazy[node]=0;
}
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[node]=aa[lo];
    return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);
  build(node*2+1,md+1,hi);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lazy[node]+=vl;too_lazy(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl);
  upd(node*2+1,md+1,hi,lt,rt,vl);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
int get(int node,int lo,int hi)
{
  too_lazy(node,lo,hi);
  if(lo==hi)
  {
    //cout<<lo<<" -- "<<seg[node]<<endl;
    return lo;
  }
  int md=(lo+hi)/2;
  too_lazy(node*2,lo,md);too_lazy(node*2+1,md+1,hi);
  if(!seg[node*2+1])return get(node*2+1,md+1,hi);
  else return get(node*2,lo,md);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  build(1,1,n);
   for(int i=1;i<=n;i++)
  {
    int id=get(1,1,n);
    //cout<<"id "<<id<<endl;
    aa[id]=i;
    upd(1,1,n,id,n,-i);
    upd(1,1,n,id,id,1e8);
  }
  for(int i=1;i<=n;i++)
    cout<<aa[i]<<" ";
  cout<<endl;
  return 0;
}