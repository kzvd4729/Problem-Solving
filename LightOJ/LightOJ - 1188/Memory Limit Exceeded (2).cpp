/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-23 01:08:44                      
*  solution_verdict: Memory Limit Exceeded                   language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1188
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int sz,arr[N+2],last[N+2],rt[N+2];
struct persistent
{
  int l,r,sm;
};
vector<persistent>seg;
persistent dm={0,0,0};
void upd(int node,int lo,int hi,int pnode,int id,int vl)
{
  if(lo==hi)
  {
    seg[node].sm=seg[pnode].sm+vl;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)
  {
    if(!seg[node].l)
    {
      seg[node].l=++sz;seg.push_back(dm);
    }
    upd(seg[node].l,lo,md,seg[pnode].l,id,vl);
    seg[node].r=seg[pnode].r;
  }
  else
  {
    if(!seg[node].r)
    {
      seg[node].r=++sz;seg.push_back(dm);
    }
    upd(seg[node].r,md+1,hi,seg[pnode].r,id,vl);
    seg[node].l=seg[pnode].l;
  }
  seg[node].sm=seg[seg[node].l].sm+seg[seg[node].r].sm;
}
int qry(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node].sm;
  int md=(lo+hi)/2;
  return qry(seg[node].l,lo,md,lt,rt)+qry(seg[node].r,md+1,hi,lt,rt);
}
int main()
{
  int t,tc=0;scanf("%d",&t);
  while(t--)
  {
    seg.clear();sz=0;seg.push_back(dm);
    int n,q;scanf("%d%d",&n,&q);
    memset(last,0,sizeof(last));
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&arr[i]);
      if(!last[arr[i]])
      {
        last[arr[i]]=i;
        rt[i]=++sz;seg.push_back(dm);
        upd(rt[i],1,n,rt[i-1],last[arr[i]],1);
      }
      else
      {
        int tmp=++sz;seg.push_back(dm);
        upd(tmp,1,n,rt[i-1],last[arr[i]],-1);
        last[arr[i]]=i;rt[i]=++sz;seg.push_back(dm);
        upd(rt[i],1,n,tmp,last[arr[i]],1);
      }
    }
    printf("Case %d:\n",++tc);
    while(q--)
    {
      int u,v;scanf("%d%d",&u,&v);
      printf("%d\n",qry(rt[v],1,n,u,v));
    }
  }
  return 0;
}