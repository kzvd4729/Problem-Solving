/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/28/2018 23:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 467 ms                                          memory_used: 4000 KB                              
*  problem: https://codeforces.com/contest/954/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1e9+7;
long n,m,a,l,r,id,ina,inb,inc,cna,cnb,cnc,now,tmpa,tmpb,tmpc;
struct data
{
  long r,p,ty;
}seg[20004];
struct matrix
{
  long mat[4][4];
};
bool cmp(data A,data B)
{
  if(A.p!=B.p)return A.p<B.p;
  else return A.ty<B.ty;
}
matrix multiply(matrix a,matrix b)
{
  matrix c;
  for(int i=1;i<=3;i++)
  {
    for(int j=1;j<=3;j++)
    {
      c.mat[i][j]=0;
      for(int k=1;k<=3;k++)
      {
        c.mat[i][j]=(c.mat[i][j]+a.mat[i][k]*b.mat[k][j])%mod;
      }
    }
  }
  return c;
}
matrix expo(long wh,long p)
{
  matrix ret;
  ret.mat[1][1]=1;
  ret.mat[1][2]=0;
  ret.mat[1][3]=0;
  ret.mat[2][1]=0;
  ret.mat[2][2]=1;
  ret.mat[2][3]=0;
  ret.mat[3][1]=0;
  ret.mat[3][2]=0;
  ret.mat[3][3]=1;
  matrix base;
  if(wh==4)
  {
    base.mat[1][1]=1;
    base.mat[1][2]=1;
    base.mat[1][3]=0;
    base.mat[2][1]=1;
    base.mat[2][2]=1;
    base.mat[2][3]=0;
    base.mat[3][1]=0;
    base.mat[3][2]=0;
    base.mat[3][3]=0;
  }
  if(wh==6)
  {
    base.mat[1][1]=0;
    base.mat[1][2]=0;
    base.mat[1][3]=0;
    base.mat[2][1]=0;
    base.mat[2][2]=1;
    base.mat[2][3]=1;
    base.mat[3][1]=0;
    base.mat[3][2]=1;
    base.mat[3][3]=1;
  }
  if(wh==7)
  {
    base.mat[1][1]=1;
    base.mat[1][2]=1;
    base.mat[1][3]=0;
    base.mat[2][1]=1;
    base.mat[2][2]=1;
    base.mat[2][3]=1;
    base.mat[3][1]=0;
    base.mat[3][2]=1;
    base.mat[3][3]=1;
  }
  while(p)
  {
    if(p&1)ret=multiply(base,ret);
    base=multiply(base,base);
    p/=2;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>a>>l>>r;
    id++;
    seg[id].r=a;
    seg[id].p=l;
    seg[id].ty=0;
    id++;
    seg[id].r=a;
    seg[id].p=r;
    seg[id].ty=1;
  }
  id++;
  seg[id].p=m;
  sort(seg+1,seg+id+1,cmp);
  ina=0;
  inb=1;
  inc=0;
  now=1;
  for(int i=1;i<=id;i++)
  {
    matrix ans;
    if(!cna&&!cnb&&cnc)ans=expo(4LL,seg[i].p-now);
    else if(cna&&!cnb&&!cnc)ans=expo(6LL,seg[i].p-now);
    else if(!cna&&!cnb&&!cnc)ans=expo(7LL,seg[i].p-now);
    else
    {
      now=seg[i].p;
      if(seg[i].r==1)
      {
        if(seg[i].ty==0)cna++;
        else cna--;
      }
      if(seg[i].r==2)
      {
        if(seg[i].ty==0)cnb++;
        else cnb--;
      }
      if(seg[i].r==3)
      {
        if(seg[i].ty==0)cnc++;
        else cnc--;
      }
      if(cna)ina=0LL;
      if(cnb)inb=0LL;
      if(cnc)inc=0LL;
      continue;
    }
    tmpa=(ans.mat[1][1]*ina+ans.mat[1][2]*inb+ans.mat[1][3]*inc)%mod;
    tmpb=(ans.mat[2][1]*ina+ans.mat[2][2]*inb+ans.mat[2][3]*inc)%mod;
    tmpc=(ans.mat[3][1]*ina+ans.mat[3][2]*inb+ans.mat[3][3]*inc)%mod;
    ina=tmpa;
    inb=tmpb;
    inc=tmpc;
    now=seg[i].p;
    if(seg[i].r==1)
    {
      if(seg[i].ty==0)cna++;
      else cna--;
    }
    if(seg[i].r==2)
    {
      if(seg[i].ty==0)cnb++;
      else cnb--;
    }
    if(seg[i].r==3)
    {
      if(seg[i].ty==0)cnc++;
      else cnc--;
    }
    if(cna)ina=0LL;
    if(cnb)inb=0LL;
    if(cnc)inc=0LL;
  }
  cout<<inb<<endl;
  return 0;
}