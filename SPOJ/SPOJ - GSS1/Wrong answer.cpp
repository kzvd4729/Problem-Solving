/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-29 23:17:15                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-GSS1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=5e4;
const long inf=1e14;
long arr[N+2],u,v,n,q;
struct segment
{
  long all,lft,rgt,mx;
}seg[4*N+2];
void build(long node,long lo,long hi)
{
  if(lo==hi)
  {
    seg[node].all=arr[lo];
    seg[node].lft=arr[lo];
    seg[node].rgt=arr[lo];
    seg[node].mx=arr[lo];
    return ;
  }
  long md=(lo+hi)/2;
  build(node*2,lo,md);
  build(node*2+1,md+1,hi);

  seg[node].all=seg[node*2].all+seg[node*2+1].all;
  seg[node].lft=max(seg[node*2].lft,max(seg[node*2].all+seg[node*2+1].lft,seg[node].all));
  seg[node].rgt=max(seg[node*2+1].rgt,max(seg[node*2+1].all+seg[node*2].rgt,seg[node].all));
  seg[node].mx=max(seg[node*2].mx,seg[node*2+1].mx);
  seg[node].mx=max(seg[node].mx,max(seg[node].lft,seg[node].rgt));
}
segment query(long node,long lo,long hi,long lt,long rt)
{
  if(lo>rt||hi<lt)return {-inf,-inf,-inf,-inf};
  if(lo>=lt&&hi<=rt)return seg[node];
  long md=(lo+hi)/2;
  segment p,p1,p2;
  p1=query(node*2,lo,md,lt,rt);
  p2=query(node*2+1,md+1,hi,lt,rt);

  if(p1.mx==-inf)return p2;
  if(p2.mx==-inf)return p1;

  p.all=p1.all+p2.all;
  p.lft=max(p1.lft,max(p1.all+p2.lft,p.all));
  p.rgt=max(p2.rgt,max(p2.all+p1.rgt,p.all));
  p.mx=max(p1.mx,p2.mx);
  p.mx=max(p.mx,max(p.lft,p.rgt));
  return p;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=1;i<=n;i++)cin>>arr[i];
  build(1,1,n);
  cin>>q;
  while(q--)
  {
    cin>>u>>v;
    cout<<query(1,1,n,u,v).mx<<endl;
  }
  return 0;
}