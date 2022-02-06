/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2019 22:29                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 73600 KB                             
*  problem: https://codeforces.com/contest/803/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,R=1e9;
int sz=1,aa[N+2],sp[N+2][22],n;
struct segment
{
  int l,r,lz,mn,f;
}seg[33*N+2];
void build(void)
{
  for(int i=1;i<=n;i++)
    sp[i][0]=aa[i];
  for(int j=1;j<20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      if(i+1<<(j-1)>n)sp[i][j]=2e9;
      else sp[i][j]=min(sp[i][j-1],sp[i+1<<(j-1)][j-1]);
    }
  }
}
int get(int lt,int rt)
{
  int dg=31-__builtin_clz(rt-lt+1);
  return min(sp[lt][dg],sp[rt-(1<<dg)+1][dg]);
}
void too_lazy(int node,int lo,int hi)
{
  if(!seg[node].f)
  {
    int l=lo%n,r=hi%n,a=(lo+n-1)/n,b=(hi+n-1)/n;
    if(!l)l=n;if(!r)r=n;
    if(a==b)seg[node].mn=get(l,r);
    else if(a==1+b)seg[node].mn=min(get(l,n),get(1,r));
    else seg[node].mn=get(1,n);
    seg[node].f=1;
  }
  if(!seg[node].lz)return ;
  if(!seg[node].l)seg[node].l=++sz;
  if(!seg[node].r)seg[node].r=++sz;
  seg[node].mn=seg[node].lz;
  seg[seg[node].l].lz=seg[node].lz;
  seg[seg[node].r].lz=seg[node].lz;
}
void upd(int node,int lo,int hi,int lt,int rt,int vl)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    seg[node].lz=vl;too_lazy(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  if(!seg[node].l)seg[node].l=++sz;
  if(!seg[node].r)seg[node].r=++sz;
  upd(seg[node].l,lo,md,lt,rt,vl);
  upd(seg[node].r,md+1,hi,lt,rt,vl);
  seg[node].mn=min(seg[seg[node].l].mn,seg[seg[node].r].mn);
}
int qry(int node,int lo,int hi,int lt,int rt)
{
  too_lazy(node,lo,hi);
  if(lo>rt||hi<lt)return 2e9;
  if(lo>=lt&&hi<=rt)return seg[node].mn;
  int md=(lo+hi)/2;
  if(!seg[node].l)seg[node].l=++sz;
  if(!seg[node].r)seg[node].r=++sz;
  int p1=qry(seg[node].l,lo,md,lt,rt);
  int p2=qry(seg[node].r,md+1,hi,lt,rt);
  return min(p1,p2);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int k;cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  build();int q;cin>>q;
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int l,r,x;cin>>l>>r>>x;
      upd(1,1,n*k,l,r,x);
    }
    else
    {
      int l,r;cin>>l>>r;
      cout<<qry(1,1,n*k,l,r)<<"\n";
    }
  }
  return 0;
}