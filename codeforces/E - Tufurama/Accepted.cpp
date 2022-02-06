/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/04/2018 22:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 343 ms                                          memory_used: 241200 KB                            
*  problem: https://codeforces.com/contest/961/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long sz,n,arr[N+2],rt[N+2],ans,r,q;
struct segment
{
  long l,r,sum;
}seg[N*50];
void upd(long node,long lo,long hi,long id,long pnode,long vl)
{
  if(lo==hi)
  {
    seg[node].sum=seg[pnode].sum+vl;
    return ;
  }
  long md=(lo+hi)/2;
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
long query(long node,long lo,long hi,long lt,long rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node].sum;
  long md=(lo+hi)/2;
  return query(seg[node].l,lo,md,lt,rt)+query(seg[node].r,md+1,hi,lt,rt);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
    cin>>n;
  for(long i=1;i<=n;i++)
  {
    cin>>arr[i];
    if(arr[i]>N)arr[i]=N;
    rt[i]=++sz;
    upd(rt[i],1,N,arr[i],rt[i-1],1);
  }
  for(long i=1;i<=n;i++)
  {
    if(arr[i]<=i)continue;
     q=query(rt[min(n,arr[i])],1,N,i,N)-query(rt[i],1,N,i,N);
    ans+=q;
  }
  cout<<ans<<endl;
  return 0;
}