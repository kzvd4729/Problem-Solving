/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/24/2018 22:01                        
*  solution_verdict: Runtime error on test 12                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 62200 KB                             
*  problem: https://codeforces.com/contest/703/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,arr[N+2],qm[N+2],sz,root[N+2],q;
map<int,int>last;
struct persistent
{
  int l,r,vl;
}seg[4*N];
void upd(int node,int lo,int hi,int pnode,int id,int vl)
{
  if(lo==hi)
  {
    seg[node].vl=seg[pnode].vl^vl;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)
  {
    if(!seg[node].l)seg[node].l=++sz;
    upd(seg[node].l,lo,md,seg[pnode].l,id,vl);
    seg[node].r=seg[pnode].r;
  }
  else
  {
    if(!seg[node].r)seg[node].r=++sz;
    upd(seg[node].r,md+1,hi,seg[pnode].r,id,vl);
    seg[node].l=seg[pnode].l;
  }
  seg[node].vl=seg[seg[node].l].vl^seg[seg[node].r].vl;
}
int query(int node,int lo,int hi,int l,int r)
{
  if(lo>r||hi<l)return 0;
  if(lo>=l&&hi<=r)return seg[node].vl;
  int md=(lo+hi)/2;
  return query(seg[node].l,lo,md,l,r)^query(seg[node].r,md+1,hi,l,r);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)cin>>arr[i];
  qm[1]=arr[1];
  for(int i=2;i<=n;i++)qm[i]=qm[i-1]^arr[i];
   for(int i=1;i<=n;i++)
  {
    if(!last[arr[i]])
    {
      root[i]=++sz;
      upd(root[i],1,N,root[i-1],i,arr[i]);
    }
    else
    {
      int tmp=++sz;
      upd(tmp,1,N,root[i-1],last[arr[i]],arr[i]);
      root[i]=++sz;
      upd(root[i],1,N,tmp,i,arr[i]);
    }
    last[arr[i]]=i;
  }
  cin>>q;
  while(q--)
  {
    int l,r;
    cin>>l>>r;
    int x=query(root[r],1,N,l,r);
    x=x^(qm[r]^qm[l-1]);
    cout<<x<<endl;
  }
  return 0;
}