/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/04/2018 22:00                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 186 ms                                          memory_used: 98800 KB                             
*  problem: https://codeforces.com/contest/961/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int sz,n,arr[N+2],rt[N+2],ans,r,q;
struct segment
{
  int l,r,sum;
}seg[N*40];
void upd(int node,int lo,int hi,int id,int pnode,int vl)
{
  if(lo==hi)
  {
    seg[node].sum=seg[pnode].sum+vl;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)
  {
    if(!seg[node].l)seg[node].l=++sz;
    upd(seg[node].l,lo,md,id,seg[pnode].l,vl);
    seg[node].r=seg[pnode].r;
  }
  else
  {
    if(!seg[node].r)seg[node].r=++sz;
    upd(seg[node].r,md+1,hi,id,seg[pnode].r,vl);
    seg[node].l=seg[pnode].l;
  }
  seg[node].sum=seg[seg[node].l].sum+seg[seg[node].r].sum;
}
int query(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node].sum;
  int md=(lo+hi)/2;
  return query(seg[node].l,lo,md,lt,rt)+query(seg[node].r,md+1,hi,lt,rt);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    if(arr[i]>N)arr[i]=N;
    rt[i]=++sz;
    upd(rt[i],1,N,arr[i],rt[i-1],1);
  }
  for(int i=1;i<=n;i++)
  {
    if(arr[i]<=i)continue;
     q=query(rt[min(n,arr[i])],1,N,i,N)-query(rt[i],1,N,i,N);
    ans+=q;
 //    q1=query(r)
//
//    r=max(arr[i],i);
//    r=min(n,r);
//    //cout<<query(rt[r],1,N,1,N)-1<<endl;
//    ///cout<<query(rt[min(n,arr[i])],1,N,i,N)-1<<endl;
//    ans+=query(rt[r],1,N,1,N)-1;
  }
  cout<<ans<<endl;
  return 0;
}