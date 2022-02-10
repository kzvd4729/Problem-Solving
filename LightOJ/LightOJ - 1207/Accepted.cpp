/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-08 11:14:20                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 632                                        memory_used (MB): 8.7                             
*  problem: https://vjudge.net/problem/LightOJ-1207
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int t,tc,n,d,x,ans,seg[4*N],lazy[4*N],here,vis[N],l,r;
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  if(lazy[node])
  {
    seg[node]=lazy[node];
    if(lo!=hi)
    {
      lazy[node*2]=lazy[node];
      lazy[node*2+1]=lazy[node];
    }
    lazy[node]=0;
  }
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    seg[node]=vl;
    if(lo!=hi)
    {
      lazy[node*2]=vl;
      lazy[node*2+1]=vl;
    }
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl);
  upd(node*2+1,md+1,hi,lt,rt,vl);
}
void query(int node,int lo,int hi,int pn)
{
  if(lazy[node])
  {
    seg[node]=lazy[node];
    if(lo!=hi)
    {
      lazy[node*2]=lazy[node];
      lazy[node*2+1]=lazy[node];
    }
    lazy[node]=0;
  }
  if(lo==hi)
  {
    here=seg[node];
    return ;
  }
  int md=(lo+hi)/2;
  if(pn<=md)query(node*2,lo,md,pn);
  else query(node*2+1,md+1,hi,pn);
}
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    memset(vis,0,sizeof(vis));
    memset(seg,0,sizeof(seg));
    memset(lazy,0,sizeof(lazy));
    ans=0;

    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
      scanf("%d%d",&l,&r);
      upd(1,1,N,l,r,i);
    }
    for(int i=1;i<N;i++)
    {
      here=0;
      query(1,1,N,i);
      vis[here]=1;
    }
    for(int i=1;i<N;i++)ans+=vis[i];
    printf("Case %d: %d\n",++tc,ans);
  }
  return 0;
}