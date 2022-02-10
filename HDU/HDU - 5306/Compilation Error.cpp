/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-04-09 17:08:50                      
*  solution_verdict: Compilation Error                       language: C                                       
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HDU-5306
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],mn[4*N+2],mx[4*N+2],lz[4*N+2];long sm[4*N+2];
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    mn[node]=mx[node]=sm[node]=aa[lo];
    return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);

  mn[node]=min(mn[node*2],mn[node*2+1]);
  mx[node]=max(mx[node*2],mx[node*2+1]);
  sm[node]=sm[node*2]+sm[node*2+1];
}
void tooLazy(int node,int lo,int hi)
{
  sm[node]=1LL*(hi-lo+1)*lz[node];
  mx[node]=mn[node]=lz[node];
  if(lo!=hi)
  {
    lz[node*2]=lz[node];lz[node*2+1]=lz[node];
  }
  lz[node]=-1;
}
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  if(lz[node]!=-1)tooLazy(node,lo,hi);
  if(lo>rt||hi<lt||mx[node]<=vl)return ;
  if(lo>=lt&&hi<=rt&&mn[node]>=vl)
  {
    lz[node]=vl;tooLazy(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl);upd(node*2+1,md+1,hi,lt,rt,vl);

  mn[node]=min(mn[node*2],mn[node*2+1]);
  mx[node]=max(mx[node*2],mx[node*2+1]);
  sm[node]=sm[node*2]+sm[node*2+1];
}
int getMX(int node,int lo,int hi,int lt,int rt)
{
  if(lz[node]!=-1)tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return mx[node];
  int md=(lo+hi)/2;
  return max(getMX(node*2,lo,md,lt,rt),getMX(node*2+1,md+1,hi,lt,rt));
}
long getSM(int node,int lo,int hi,int lt,int rt)
{
  if(lz[node]!=-1)tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return sm[node];
  int md=(lo+hi)/2;
  return getSM(node*2,lo,md,lt,rt)+getSM(node*2+1,md+1,hi,lt,rt);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;scanf("%d",&t);
  while(t--)
  {
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&aa[i]);

    for(int i=1;i<=4*n;i++)
      sm[i]=0,mn[i]=0,mx[i]=0,lz[i]=-1;

    build(1,1,n);
    while(m--)
    {
      int ty,x,y;scanf("%d%d%d",&ty,&x,&y);
      if(ty==0)
      {
        int vl;scanf("%d",&vl);upd(1,1,n,x,y,vl);
      }
      else if(ty==1)printf("%d\n",getMX(1,1,n,x,y));
      else printf("%lld\n",getSM(1,1,n,x,y));
    }
  }
  return 0;
}