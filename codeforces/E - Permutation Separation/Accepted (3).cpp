/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/30/2020 22:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 499 ms                                          memory_used: 97900 KB                             
*  problem: https://codeforces.com/contest/1295/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int pp[N+2],aa[N+2],po[N+2];
long qm[N+2];
 long seg[5*N+2],lazy[5*N+2];
void tooLazy(int node,int lo,int hi)
{
  seg[node]+=lazy[node];
  if(lo!=hi)
    lazy[node*2]+=lazy[node],lazy[node*2+1]+=lazy[node];
  lazy[node]=0;
}
void upd(int node,int lo,int hi,int lt,int rt,long ad)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lazy[node]+=ad;tooLazy(node,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(node*2,lo,md,lt,rt,ad);upd(node*2+1,md+1,hi,lt,rt,ad);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
long get(int node,int lo,int hi,int lt,int rt)
{
  tooLazy(node,lo,hi);
  if(lo>rt||hi<lt)return 1e18;
  if(lo>=lt&&hi<=rt)
    return seg[node];
  int md=(lo+hi)/2;
  return min(get(node*2,lo,md,lt,rt),get(node*2+1,md+1,hi,lt,rt));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>pp[i],po[pp[i]]=i;
  for(int i=1;i<=n;i++)cin>>aa[i];
   for(int i=1;i<=n;i++)qm[i]=qm[i-1]+aa[i],upd(1,1,n,i,i,qm[i]);
  long ans=min(aa[1],aa[n]);
  for(int i=1;i<=n;i++)
  {
    upd(1,1,n,po[i],n,-aa[po[i]]);
    if(po[i]>1)upd(1,1,n,1,po[i]-1,aa[po[i]]);
     ans=min(ans,get(1,1,n,1,n-1));
  }
  cout<<ans<<endl;
  return 0;
}