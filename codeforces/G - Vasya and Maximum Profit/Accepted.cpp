/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/27/2019 18:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 545 ms                                          memory_used: 92800 KB                             
*  problem: https://codeforces.com/contest/1107/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int cc[N+2];long dd[N+2];
struct segment
{
  long lt,rt,mx,al;
}seg[4*N+2];
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[node]={cc[lo],cc[lo],cc[lo],cc[lo]};
    return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  segment p1=seg[node*2],p2=seg[node*2+1],p;
  p.al=p1.al+p2.al;
  p.lt=max(p1.lt,p1.al+p2.lt);p.lt=max(p.lt,p.al);
  p.rt=max(p2.rt,p2.al+p1.rt);p.rt=max(p.rt,p.al);
  p.mx=max(p1.mx,p2.mx);
  p.mx=max(p.mx,max(p.lt,p.rt));
  p.mx=max(p.mx,p1.rt+p2.lt);seg[node]=p;
}
segment qry(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return {0,0,0,0};
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  segment p1,p2,p;
  p1=qry(node*2,lo,md,lt,rt);
  p2=qry(node*2+1,md+1,hi,lt,rt);
  p.al=p1.al+p2.al;
  p.lt=max(p1.lt,p1.al+p2.lt);p.lt=max(p.lt,p.al);
  p.rt=max(p2.rt,p2.al+p1.rt);p.rt=max(p.rt,p.al);
  p.mx=max(p1.mx,p2.mx);
  p.mx=max(p.mx,max(p.lt,p.rt));
  p.mx=max(p.mx,p1.rt+p2.lt);
  return p;
}
/**************** Sparse for Range Min ***************/
long sp_min[N+2][21],SP[N+2];
void Sparse_Min_Build(int n)
{
  for(int i=1;i<=n;i++)
    sp_min[i][0]=SP[i];
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if((i+(1<<(j-1)))>n)continue;
      sp_min[i][j]=max(sp_min[i][j-1],sp_min[i+(1<<(j-1))][j-1]);
    }
  }
}
long Query_Max(int lt,int rt)
{
  //if(rt<lt)return 1e9;
  int dg=31-__builtin_clz(rt-lt+1);
  return max(sp_min[lt][dg],sp_min[rt-(1<<dg)+1][dg]);
}
/////////////////////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,a;cin>>n>>a;
  for(int i=1;i<=n;i++)
  {
    cin>>dd[i]>>cc[i];
    cc[i]=a-cc[i];
  }
  long ans=0;
  for(int i=1;i<=n;i++)ans=max(ans,cc[i]*1LL);
  for(int i=n;i>1;i--)
    SP[i]=(dd[i]-dd[i-1])*(dd[i]-dd[i-1]);
  /*for(int i=1;i<=n;i++)
    cout<<cc[i]<<" ";
  cout<<endl;*/
  Sparse_Min_Build(n);build(1,1,n);
  //cout<<Query_Max(3,5)<<endl;
  for(int i=2;i<=n;i++)
  {
    int lo=i,hi=n,md,lt,rt;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      long mx=Query_Max(i,md);
      if(mx>SP[i])hi=md;
      else lo=md;
    }
    for(md=hi;md>=lo;md--)
    {
      long mx=Query_Max(i,md);
      if(mx<=SP[i])break;
    }
    rt=md;
     lo=2,hi=i,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      long mx=Query_Max(md,i);
      if(mx>SP[i])lo=md;
      else hi=md;
    }
    for(md=lo;md<=hi;md++)
    {
      long mx=Query_Max(md,i);
      if(mx<=SP[i])break;
    }
    lt=md-1;
    //cout<<lt<<" "<<rt<<endl;
    //cout<<qry(1,1,n,lt,rt).mx<<endl;
    ans=max(ans,qry(1,1,n,lt,rt).mx-SP[i]);
  }
  cout<<ans<<endl;
  return 0;
}