/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/30/2020 22:36                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 561 ms                                          memory_used: 109600 KB                            
*  problem: https://codeforces.com/contest/1295/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
long pp[N+2],aa[N+2],po[N+2];
long qm[N+2];
 long seg[5*N+2],lazy[5*N+2];
void tooLazy(long node,long lo,long hi)
{
  seg[node]+=lazy[node];
  if(lo!=hi)
    lazy[node*2]+=lazy[node],lazy[node*2+1]+=lazy[node];
  lazy[node]=0;
}
void build(long node,long lo,long hi)
{
  if(lo==hi){seg[node]=qm[lo];return ;}
  long md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
void upd(long node,long lo,long hi,long lt,long rt,long ad)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lazy[node]+=ad;tooLazy(node,lo,hi);
    return ;
  }
  long md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,ad);upd(node*2+1,md+1,hi,lt,rt,ad);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
long get(long node,long lo,long hi,long lt,long rt)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return 1e18;
  if(lo>=lt&&hi<=rt)
    return seg[node];
  long md=(lo+hi)/2;
  return min(get(node*2,lo,md,lt,rt),get(node*2+1,md+1,hi,lt,rt));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=1;i<=n;i++)cin>>pp[i],po[pp[i]]=i;
  for(long i=1;i<=n;i++)cin>>aa[i];
   for(long i=1;i<=n;i++)qm[i]=qm[i-1]+aa[i];
  build(1,1,n);long ans=min(aa[1],aa[n]);
  for(long i=1;i<=n;i++)
  {
    upd(1,1,n,po[i],n,-aa[po[i]]);
    if(po[i]>1)upd(1,1,n,1,po[i]-1,aa[po[i]]);
     ans=min(ans,get(1,1,n,1,n-1));
  }
  cout<<ans<<endl;
  return 0;
}