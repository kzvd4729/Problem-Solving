/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/06/2019 00:11                        
*  solution_verdict: Time limit exceeded on test 27          language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 29800 KB                             
*  problem: https://codeforces.com/contest/1132/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
long aa[N+2],bb[N+2],cc[N+2],ex[N+2];
struct segment
{
  long lf,ex,id;
}seg[5*N+2];
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[node]={cc[lo],ex[lo],lo};return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);build(node*2+1,md+1,hi);
  if(seg[node*2].lf<=seg[node*2+1].lf)
    seg[node]=seg[node*2];
  else seg[node]=seg[node*2+1];
}
inline void upd(int node,int lo,int hi,int id,long vl,long ex)
{
  if(lo==hi)
  {
    seg[node].lf=vl;seg[node].ex=ex;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl,ex);
  else upd(node*2+1,md+1,hi,id,vl,ex);
  if(seg[node*2].lf<=seg[node*2+1].lf)
    seg[node]=seg[node*2];
  else seg[node]=seg[node*2+1];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=1;i<=n;i++)
    cin>>bb[i];
  for(int i=1;i<=n;i++)
  {
    cc[i]=aa[i]/bb[i];
    ex[i]=aa[i]%bb[i];
  }
  long lo=0,hi=2e12+2,md,ans=-1;
  while(lo<=hi)
  {
    md=(lo+hi)/2;build(1,1,n);int f=0;
    for(int i=1;i<k;i++)
    {
      segment sg=seg[1];
      sg.lf+=md/bb[sg.id];sg.ex+=md%bb[sg.id];
      if(sg.ex>=bb[sg.id])sg.lf++,sg.ex-=bb[sg.id];
      upd(1,1,n,sg.id,sg.lf,sg.ex);
      if(seg[1].lf<i)
      {
        f=1;break;
      }
    }
    if(f)lo=md+1;
    else
    {
      ans=md;hi=md-1;
    }
  }
  cout<<ans<<endl;
  return 0;
}