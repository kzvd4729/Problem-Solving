/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/25/2020 17:07                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 161300 KB                            
*  problem: https://codeforces.com/contest/1311/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5,inf=1e9,R=2e8;
struct segment
{
  int l,r,cnt;long sm;
}seg[34*N+2];
int sz;
void upd(int node,int lo,int hi,int id,long vl)
{
  //cout<<lo<<" "<<hi<<" "<<id<<endl;getchar();
  if(lo==hi)
  {
    seg[node].sm+=vl;seg[node].cnt++;
    return ;
  }
  int md=(lo+hi)/2;
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
pair<int,int>get(int node,int lo,int hi,int id)
{
  if(hi<=id)return {seg[node].cnt,seg[node].sm};
  if(lo>id)return {0,0};int md=(lo+hi)/2;
  pair<int,int>p1=get(seg[node].l,lo,md,id);
  pair<int,int>p2=get(seg[node].r,md+1,hi,id);
  return {p1.first+p2.first,p1.second+p2.second};
}
pair<int,int>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>pp[i].first;
  for(int i=1;i<=n;i++)cin>>pp[i].second;
   sort(pp+1,pp+n+1);long ans=0;
   /*for(int i=1;i<=n;i++)
    cout<<pp[i].first<<" ";
  cout<<endl;
  for(int i=1;i<=n;i++)
    cout<<pp[i].second<<" ";
  cout<<endl;*/
    sz=1;
  for(int i=1;i<=n;i++)
  {
    upd(1,0,2*R,pp[i].second+R,pp[i].first);
    pair<int,int>p=get(1,0,2*R,pp[i].second+R);
    //cout<<p.first<<" ** "<<p.second<<endl;
    ans+=pp[i].first*p.first-p.second;
  }
     cout<<ans<<endl;
  return 0;
}