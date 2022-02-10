/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-14 19:56:12                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1371                                       memory_used (MB): 50.9                            
*  problem: https://vjudge.net/problem/LightOJ-1411
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=250000;
const int inv=1e9;
long seg[5*N+2],lza[5*N+2],lzb[5*N+2],lzc[5*N+2],lzd[5*N+2];
void too_lazy(int node,int lo,int hi)
{
  long df=hi-lo+1;
  seg[node]+=df*lzc[node]+((df*(df+1))/2)*(lza[node]+lzb[node]);
  if(lzd[node]!=inv)seg[node]+=df*lzd[node];
  if(lo!=hi)
  {
    if(lzd[node]!=inv)
    {
      lzd[node*2]=lzd[node];seg[node*2]=0;
      lza[node*2]=0;lzb[node*2]=0;lzc[node*2]=0;

      lzd[node*2+1]=lzd[node];seg[node*2+1]=0;
      lza[node*2+1]=0;lzb[node*2+1]=0;lzc[node*2+1]=0;
    }
    lzc[node*2]+=lzc[node];lzc[node*2+1]+=lzc[node];
    int md=(lo+hi)/2;

    lza[node*2]+=lza[node];lza[node*2+1]+=lza[node];
    lzc[node*2+1]+=(md-lo+1)*lza[node];

    lzb[node*2]+=lzb[node];lzb[node*2+1]+=lzb[node];
    lzc[node*2]+=(hi-md)*lzb[node];
  }
  lza[node]=0;lzb[node]=0;lzc[node]=0;lzd[node]=inv;
}
void upd(int node,int lo,int hi,int lt,int rt,int ty,int vl)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    if(ty==1)lzc[node]+=lo-lt,lza[node]++;
    else if(ty==2)lzc[node]+=rt-hi,lzb[node]++;
    else
    {
      lzd[node]=vl;seg[node]=0;lza[node]=0;lzb[node]=0;lzc[node]=0;
    }
    too_lazy(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,ty,vl);upd(node*2+1,md+1,hi,lt,rt,ty,vl);
  seg[node]=seg[node*2]+seg[node*2+1];
}
long qry(int node,int lo,int hi,int lt,int rt)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return 0;if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  return qry(node*2,lo,md,lt,rt)+qry(node*2+1,md+1,hi,lt,rt);
}
int main()
{
  int t,tc=0;scanf("%d",&t);
  while(t--)
  {
    int q;scanf("%d",&q);
    memset(seg,0,sizeof(seg));memset(lza,0,sizeof(lza));
    memset(lzb,0,sizeof(lzb));memset(lzc,0,sizeof(lzc));
    for(int i=0;i<=5*N;i++)lzd[i]=inv;
    printf("Case %d:\n",++tc);
    while(q--)
    {
      getchar();
      char ch;scanf("%c",&ch);
      if(ch=='A')
      {
        int lt,rt;scanf("%d%d",&lt,&rt);upd(1,1,N,lt,rt,1,0);
      }
      else if(ch=='B')
      {
        int lt,rt;scanf("%d%d",&lt,&rt);upd(1,1,N,lt,rt,2,0);
      }
      else if(ch=='C')
      {
        int lt,rt,vl;scanf("%d%d%d",&lt,&rt,&vl);upd(1,1,N,lt,rt,3,vl);
      }
      else
      {
        int lt,rt;scanf("%d%d",&lt,&rt);printf("%lld\n",qry(1,1,N,lt,rt));
      }
    }
  }
  return 0;
}