/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/25/2020 17:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 421 ms                                          memory_used: 216100 KB                            
*  problem: https://codeforces.com/contest/1311/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5,inf=1e9,R=2e8;
struct segment
{
  long l,r,cnt;long sm;
}seg[34*N+2];
long sz;
void upd(long node,long lo,long hi,long id,long vl)
{
  //cout<<lo<<" "<<hi<<" "<<id<<endl;getchar();
  if(lo==hi)
  {
    seg[node].sm+=vl;seg[node].cnt++;
    return ;
  }
  long md=(lo+hi)/2;
  if(id<=md)
  {
    if(!seg[node].l)seg[node].l=++sz;
    upd(seg[node].l,lo,md,id,vl);
  }
  else
  {
    if(!seg[node].r)seg[node].r=++sz;
    upd(seg[node].r,md+1,hi,id,vl); 
  }
  seg[node].sm=seg[seg[node].l].sm+seg[seg[node].r].sm;
  seg[node].cnt=seg[seg[node].l].cnt+seg[seg[node].r].cnt;
}
pair<long,long>get(long node,long lo,long hi,long id)
{
  if(hi<=id)return {seg[node].cnt,seg[node].sm};
  if(lo>id)return {0,0};long md=(lo+hi)/2;
  pair<long,long>p1=get(seg[node].l,lo,md,id);
  pair<long,long>p2=get(seg[node].r,md+1,hi,id);
  return {p1.first+p2.first,p1.second+p2.second};
}
pair<long,long>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=1;i<=n;i++)cin>>pp[i].first;
  for(long i=1;i<=n;i++)cin>>pp[i].second;
   sort(pp+1,pp+n+1);long ans=0;
   /*for(long i=1;i<=n;i++)
    cout<<pp[i].first<<" ";
  cout<<endl;
  for(long i=1;i<=n;i++)
    cout<<pp[i].second<<" ";
  cout<<endl;*/
    sz=1;
  for(long i=1;i<=n;i++)
  {
    upd(1,0,2*R,pp[i].second+R,pp[i].first);
    pair<long,long>p=get(1,0,2*R,pp[i].second+R);
    //cout<<p.first<<" ** "<<p.second<<endl;
    ans+=pp[i].first*p.first-p.second;
  }
  cout<<ans<<endl;
  return 0;
}