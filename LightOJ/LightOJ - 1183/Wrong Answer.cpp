/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-15 14:13:47                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1183
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int t,tc,n,ty,seg[4*N],lazy[4*N],q;
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  if(lazy[node])
  {
    seg[node]=(hi-lo+1)*lazy[node];
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
    seg[node]=(hi-lo+1)*vl;
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
  seg[node]=seg[node*2]+seg[node*2+1];
}
int query(int node,int lo,int hi,int lt,int rt)
{
  if(lazy[node])
  {
    seg[node]=(hi-lo+1)*lazy[node];
    if(lo!=hi)
    {
      lazy[node*2]=lazy[node];
      lazy[node*2+1]=lazy[node];
    }
    lazy[node]=0;
  }
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  return query(node*2,lo,md,lt,rt)+query(node*2+1,md+1,hi,lt,rt);
}
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d",&n,&q);
    memset(lazy,0,sizeof(lazy));
    memset(seg,0,sizeof(seg));
    printf("Case %d:\n",++tc);
    int ty,lt,rt,vl;
    while(q--)
    {
      scanf("%d",&ty);
      if(ty==1)
      {
        scanf("%d%d%d",&lt,&rt,&vl);
        lt++,rt++;
        upd(1,1,n,lt,rt,vl);
      }
      else
      {
        scanf("%d%d",&lt,&rt);
        lt++,rt++;
        int up=query(1,1,n,lt,rt);
        int dw=rt-lt+1;
        int gcd=__gcd(up,dw);
        up/=gcd;
        dw/=gcd;
        if(dw==1||up==0)printf("%d\n",up);
        else printf("%d/%d\n",up,dw);
      }
    }
  }
  return 0;
}