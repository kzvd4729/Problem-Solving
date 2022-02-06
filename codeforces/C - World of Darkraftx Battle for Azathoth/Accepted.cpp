/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/01/2020 20:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 795 ms                                          memory_used: 134000 KB                            
*  problem: https://codeforces.com/contest/1320/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6+10,inf=1e9;
pair<long,long>att[N+2],dfn[N+2];
long aa[N+2],bb[N+2],seg[5*N+2],lz[5*N+2];
void build(long node,long lo,long hi)
{
  if(lo==hi)
  {
    seg[node]=-bb[lo+1];return ;
  }
  long md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  seg[node]=max(seg[node*2],seg[node*2+1]);
}
void tooLazy(long node,long lo,long hi)
{
 seg[node]+=lz[node];
 if(lo!=hi)
 {
  lz[node*2]+=lz[node];
  lz[node*2+1]+=lz[node];
 }
 lz[node]=0;
}
void add(long node,long lo,long hi,long lt,long rt,long vl)
{
 tooLazy(node,lo,hi);
 if(lo>rt||hi<lt)return ;
 if(lo>=lt&&hi<=rt)
 {
  lz[node]+=vl;tooLazy(node,lo,hi);
  return ;
 }
  long md=(lo+hi)/2;
  add(node*2,lo,md,lt,rt,vl);
  add(node*2+1,md+1,hi,lt,rt,vl);
  seg[node]=max(seg[node*2],seg[node*2+1]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m,p;cin>>n>>m>>p;
  for(long i=1;i<=n;i++)cin>>att[i].first>>att[i].second;
  for(long i=1;i<=m;i++)cin>>dfn[i].first>>dfn[i].second;
   vector<vector<long> >mnt(p);
  for(long i=0;i<p;i++)
  {
    mnt[i].resize(3);
    cin>>mnt[i][0]>>mnt[i][1]>>mnt[i][2];
  }
  sort(att+1,att+n+1);sort(dfn+1,dfn+m+1);
  sort(mnt.begin(),mnt.end());
   for(long i=0;i<=N;i++)aa[i]=2e9+1,bb[i]=2e9+1;
  for(long i=n;i>=1;i--)aa[att[i].first]=min(aa[att[i].first],att[i].second);
  for(long i=m;i>=1;i--)bb[dfn[i].first]=min(bb[dfn[i].first],dfn[i].second);
  for(long i=N-1;i>=0;i--)aa[i]=min(aa[i],aa[i+1]),bb[i]=min(bb[i],bb[i+1]);
  long ans=-(aa[0]+bb[0]);
  // for(long i=0;i<=10;i++)
  //  cout<<bb[i]<<" ";
  // cout<<endl;
   long R=1e6;build(1,1,R);
   for(auto x:mnt)
  {
    add(1,1,R,x[1],R,x[2]);
    ans=max(ans,seg[1]-aa[x[0]+1]);
  }
  cout<<ans<<endl;
  return 0;
}