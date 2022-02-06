/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/26/2018 00:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1073/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long seg[5*N+2],tr;
void upd(long node,long lo,long hi,long id,long vl)
{
  if(lo==hi)
  {
    seg[node]=vl;return ;
  }
  long md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);
  seg[node]=seg[node*2]+seg[node*2+1];
}
void qry(long node,long lo,long hi,long vl)
{
  if(lo==hi)
  {
    tr=lo;return ;
  }
  long md=(lo+hi)/2;
  if(seg[node*2]>vl)qry(node*2,lo,md,vl);
  else qry(node*2+1,md+1,hi,vl-seg[node*2]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m;cin>>n>>m;
  for(long i=1;i<=n;i++)
  {
    long x;cin>>x;upd(1,1,n,i,x);
  }
  long ans=0,sz=n;
  while(sz&&m)
  {
    ans+=(m/seg[1])*sz;m%=seg[1];
    qry(1,1,n,m);upd(1,1,n,tr,0);sz--;
  }
  cout<<ans<<endl;
  return 0;
}