/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-18 14:59:31                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1170                                       memory_used (MB): 15.4                            
*  problem: https://vjudge.net/problem/SPOJ-DQUERY
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
//..............................................................................
int sz;
struct segment
{
  int l,r,sm;
}seg[10*N+2];
void upd(int node,int lo,int hi,int pnode,int id,int vl)
{
  if(lo==hi){seg[node].sm=seg[pnode].sm+vl;return ;}
  int md=(lo+hi)/2;
  if(id<=md)
  {
    seg[node].l=++sz;
    upd(seg[node].l,lo,md,seg[pnode].l,id,vl);
    seg[node].r=seg[pnode].r;
  }
  else
  {
    seg[node].r=++sz;
    upd(seg[node].r,md+1,hi,seg[pnode].r,id,vl);
    seg[node].l=seg[pnode].l;
  }
  seg[node].sm=seg[seg[node].l].sm+seg[seg[node].r].sm;
}
int get(int node,int lo,int hi,int lt,int rt)
{
  if(lo>=lt&&hi<=rt)return seg[node].sm;
  if(lo>rt||hi<lt)return 0;
  int md=(lo+hi)/2;
  return get(seg[node].l,lo,md,lt,rt)+get(seg[node].r,md+1,hi,lt,rt);
}
int last[N+2],root[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;int tmp=++sz;
    upd(tmp,1,N,root[i-1],i,1);
    if(last[x]){root[i]=++sz;upd(root[i],1,N,tmp,last[x],-1);}
    else root[i]=tmp;

    last[x]=i;
  }
  int q;cin>>q;
  while(q--)
  {
    int lt,rt;cin>>lt>>rt;
    cout<<get(root[rt],1,N,lt,rt)<<endl;
  }
  return 0;
}