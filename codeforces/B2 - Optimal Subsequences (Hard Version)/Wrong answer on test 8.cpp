/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/25/2019 11:19                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 48500 KB                             
*  problem: https://codeforces.com/contest/1261/problem/B2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5,inf=1e9;
int aa[N+2],nw,rot[N+2];
map<int,int>cn,rv;
struct persistent
{
 int l,r,sm;
}seg[N*20+2];
void upd(int node,int pnode,int lo,int hi,int id)
{
 if(lo==hi)
 {
  seg[node].sm=seg[pnode].sm+1;
  return ;
 }
 int md=(lo+hi)/2;
 if(id<=md)
 {
  if(!seg[node].l)seg[node].l=++nw;
  upd(seg[node].l,seg[pnode].l,lo,md,id);
  seg[node].r=seg[pnode].r;
 }
 else
 {
  if(!seg[node].r)seg[node].r=++nw;
  upd(seg[node].r,seg[pnode].r,md+1,hi,id);
  seg[node].l=seg[pnode].l; 
 }
 seg[node].sm=seg[seg[node].l].sm+seg[seg[node].r].sm;
}
int get(int node,int lo,int hi,int vl)
{
 if(lo>=vl)return seg[node].sm;
 if(hi<vl)return 0;
  int md=(lo+hi)/2;
 int p1=get(seg[node].l,lo,md,vl);
 int p2=get(seg[node].r,md+1,hi,vl);
 return p1+p2;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<int>v;
  for(int i=1;i<=n;i++)cin>>aa[i],v.push_back(aa[i]);
  sort(v.begin(),v.end());
 v.erase(unique(v.begin(),v.end()),v.end());
 for(int i=0;i<v.size();i++)
  cn[v[i]]=i+1,rv[i+1]=v[i];
 for(int i=1;i<=n;i++)aa[i]=cn[aa[i]];
  for(int i=1;i<=n;i++)
 {
  rot[i]=++nw;upd(rot[i],rot[i-1],1,n,aa[i]);
 }
 int q;cin>>q;
 while(q--)
 {
  int k,id;cin>>k>>id;
   int lo=1,hi=n,md;
  while(hi-lo>2)
  {
   md=(lo+hi)/2;
   if(get(rot[n],1,n,md)<k)hi=md;
   else lo=md;
  }
  for(md=hi;md>=lo;md--)
   if(get(rot[n],1,n,md)>=k)break;
  int lw=md;
   lo=1,hi=n,md;
  while(hi-lo>2)
  {
   md=(lo+hi)/2;
   if(get(rot[md],1,n,lw)<id)lo=md;
   else hi=md;
  }
  for(md=lo;md<=hi;md++)
   if(get(rot[md],1,n,lw)>=id)break;
  cout<<rv[aa[md]]<<"\n";
 }
  return 0;
}