/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/27/2018 14:25                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 13100 KB                             
*  problem: https://codeforces.com/contest/719/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
long nw,nx,lazy[400005];
int n,m,arr[100005],l,r,x,ty;
struct segment
{
  long now,next;
}seg[400005];
struct matrix
{
  long mat[3][3];
};
inline matrix multiply(matrix a,matrix b)
{
  matrix c;
  for(int i=1;i<=2;i++)
  {
    for(int j=1;j<=2;j++)
    {
      c.mat[i][j]=0;
      for(int k=1;k<=2;k++)
      {
        c.mat[i][j]=(c.mat[i][j]+a.mat[i][k]*b.mat[k][j])%mod;
      }
    }
  }
  return c;
}
matrix expo(long p)
{
  matrix ret,base;
  ret.mat[1][1]=1;
  ret.mat[1][2]=0;
  ret.mat[2][1]=0;
  ret.mat[2][2]=1;
  base.mat[1][1]=1;
  base.mat[1][2]=1;
  base.mat[2][1]=1;
  base.mat[2][2]=0;
  while(p)
  {
    if(p&1)ret=multiply(ret,base);
    base=multiply(base,base);
    p/=2;
  }
  return ret;
}
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    matrix ans=expo(arr[lo]);
    seg[node].now=ans.mat[2][1];
    seg[node].next=ans.mat[1][1];
    return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);
  build(node*2+1,md+1,hi);
  seg[node].now=(seg[node*2].now+seg[node*2+1].now)%mod;
  seg[node].next=(seg[node*2].next+seg[node*2+1].next)%mod;
}
void upd(int node,int lo,int hi,int lt,int rt,int in)
{
  if(lo>rt||hi<lt)return ;
  if(lazy[node])
  {
    matrix ans=expo(lazy[node]);
    nw=(ans.mat[2][1]*seg[node].next+ans.mat[2][2]*seg[node].now)%mod;
    nx=(ans.mat[1][1]*seg[node].next+ans.mat[1][2]*seg[node].now)%mod;
    seg[node].now=nw;
    seg[node].next=nx;
    if(lo!=hi)
    {
      lazy[node*2]+=lazy[node];
      lazy[node*2+1]+=lazy[node];
    }
    lazy[node]=0;
  }
  if(lo>=lt&&hi<=rt)
  {
    matrix ans=expo(in);
    nw=(ans.mat[2][1]*seg[node].next+ans.mat[2][2]*seg[node].now)%mod;
    nx=(ans.mat[1][1]*seg[node].next+ans.mat[1][2]*seg[node].now)%mod;
    seg[node].now=nw;
    seg[node].next=nx;
    if(lo!=hi)
    {
      lazy[node*2]+=in;
      lazy[node*2+1]+=in;
    }
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,in);
  upd(node*2+1,md+1,hi,lt,rt,in);
  seg[node].now=(seg[node*2].now+seg[node*2+1].now)%mod;
  seg[node].next=(seg[node*2].next+seg[node*2+1].next)%mod;
 }
segment query(int node,int lo,int hi,int lt,int rt)
{
  if(lazy[node])
  {
    matrix ans=expo(lazy[node]);
    nw=(ans.mat[2][1]*seg[node].next+ans.mat[2][2]*seg[node].now)%mod;
    nx=(ans.mat[1][1]*seg[node].next+ans.mat[1][2]*seg[node].now)%mod;
    seg[node].now=nw;
    seg[node].next=nx;
    if(lo!=hi)
    {
      lazy[node*2]+=lazy[node];
      lazy[node*2+1]+=lazy[node];
    }
    lazy[node]=0;
  }
  if(lo>rt||hi<lt)return {0LL,0LL};
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  segment p1=query(node*2,lo,md,lt,rt);
  segment p2=query(node*2+1,md+1,hi,lt,rt);
  return {(p1.now+p2.now)%mod,(p1.next+p2.next)%mod};
}
int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
  build(1,1,n);
  while(m--)
  {
    scanf("%d%d%d",&ty,&l,&r);
    if(ty==1)
    {
      scanf("%d",&x);
      upd(1,1,n,l,r,x);
    }
    else printf("%lld\n",query(1,1,n,l,r).now);
  }
  return 0;
}