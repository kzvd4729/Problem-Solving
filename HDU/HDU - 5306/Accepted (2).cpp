/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-04-09 19:02:15                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 2059                                       memory_used (MB): 21                              
*  problem: https://vjudge.net/problem/HDU-5306
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],sc[4*N+2],mx[4*N+2],cn[4*N+2],lz[4*N+2];long sm[4*N+2];
void merge(int node)
{
  int l=node*2,r=node*2+1;sm[node]=sm[l]+sm[r];
  if(mx[l]==mx[r])
  {
    mx[node]=mx[l],cn[node]=cn[l]+cn[r];
    sc[node]=max(sc[l],sc[r]);
  }
  else if(mx[l]>mx[r])
  {
    mx[node]=mx[l],cn[node]=cn[l];
    sc[node]=max(sc[l],mx[r]);
  }
  else
  {
    mx[node]=mx[r],cn[node]=cn[r];
    sc[node]=max(sc[r],mx[l]);
  }
}
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    mx[node]=sm[node]=aa[lo];sc[node]=-1,cn[node]=1;
    return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  merge(node);
}
void tooLazy(int node,int lo,int hi)
{
  if(lz[node]>=mx[node]){lz[node]=-1;return;}
  if(lz[node]<mx[node])
  {
    sm[node]-=1LL*cn[node]*(mx[node]-lz[node]);
    mx[node]=lz[node];
  }
  if(lo!=hi)
  {
    lz[node*2]=lz[node],lz[node*2+1]=lz[node];
  }
  lz[node]=-1;
}
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  if(lz[node]!=-1)tooLazy(node,lo,hi);
  if(lo>rt||hi<lt||mx[node]<=vl)return ;
  if(lo>=lt&&hi<=rt&&sc[node]<vl)
  {
    //cout<<lo<<" ** "<<hi<<endl;
    lz[node]=vl;tooLazy(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,vl);upd(node*2+1,md+1,hi,lt,rt,vl);
  merge(node);
}
int getMX(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lz[node]!=-1)tooLazy(node,lo,hi);
  if(lo>=lt&&hi<=rt)return mx[node];
  int md=(lo+hi)/2;
  return max(getMX(node*2,lo,md,lt,rt),getMX(node*2+1,md+1,hi,lt,rt));
}
long getSM(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lz[node]!=-1)tooLazy(node,lo,hi);
  if(lo>=lt&&hi<=rt)return sm[node];
  int md=(lo+hi)/2;
  return getSM(node*2,lo,md,lt,rt)+getSM(node*2+1,md+1,hi,lt,rt);
}
int main()
{
  int t;scanf("%d",&t);
  while(t--)
  {
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&aa[i]);

    for(int i=1;i<=4*n;i++)
      sm[i]=0,sc[i]=0,mx[i]=0,lz[i]=-1,cn[i]=0;

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