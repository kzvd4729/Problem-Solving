/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-21 15:37:38                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1890                                       memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-wet-shark-and-kth-largest-number
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,q,nw,rt[N+2],mm[N+2];
pair<int,int>pp[N+2];
struct segment
{
  int l,r,sum;
}seg[50*N+2];
void upd(int node,int lo,int hi,int pnode,int id)
{
  if(lo==hi)
  {
    seg[node].sum=seg[pnode].sum+1;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)
  {
    if(!seg[node].l)seg[node].l=++nw;
    upd(seg[node].l,lo,md,seg[pnode].l,id);
    seg[node].r=seg[pnode].r;
  }
  else
  {
    if(!seg[node].r)seg[node].r=++nw;
    upd(seg[node].r,md+1,hi,seg[pnode].r,id);
    seg[node].l=seg[pnode].l;
  }
  seg[node].sum=seg[seg[node].l].sum+seg[seg[node].r].sum;
}
int qry(int node,int lo,int hi,int kth)
{
  if(lo==hi)return lo;
  int md=(lo+hi)/2;
  if(seg[seg[node].l].sum>=kth)return qry(seg[node].l,lo,md,kth);
  else return qry(seg[node].r,md+1,hi,kth-seg[seg[node].l].sum);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>q;for(int i=1;i<=n;i++){cin>>pp[i].first;pp[i].second=i;mm[i]=pp[i].first;}
  sort(pp+1,pp+n+1);
  for(int i=n;i>=1;i--)
  {
    rt[i]=++nw;
    upd(rt[i],1,n,rt[i+1],pp[i].second);
  }
  while(q--)
  {
    int nd,kth;cin>>nd>>kth;
    int id=lower_bound(pp+1,pp+n+1,make_pair(nd,-1))-pp;
    cout<<mm[qry(rt[id],1,n,kth)]<<endl;
  }
  return 0;
}