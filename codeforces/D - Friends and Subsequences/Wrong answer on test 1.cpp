/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/12/2018 01:48                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++17                               
*  run_time: 0 ms                                            memory_used: 9700 KB                              
*  problem: https://codeforces.com/contest/689/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
const int inf=INT_MAX;
int seg[4*N][2],n,a[N+2],b[N+2],ans,lo,hi,md;
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[node][0]=a[lo];
    seg[node][1]=b[lo];
    return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);
  build(node*2+1,md+1,hi);
  seg[node][0]=max(seg[node*2][0],seg[node*2+1][0]);
  seg[node][1]=min(seg[node*2][1],seg[node*2+1][1]);
  ///cout<<node<<" "<<lo<<" "<<hi<<" "<<seg[node][0]<<" "<<seg[node][1]<<endl;
}
pair<int,int>query(int node,int lo,int hi,int l,int r)
{
  if(lo>r||hi<l)return {-inf,inf};
  if(lo>=l&&hi<=r)return {seg[node][0],seg[node][1]};
  int md=(lo+hi)/2;
  pair<int,int>p1=query(node*2,lo,md,l,r);
  pair<int,int>p2=query(node*2+1,md+1,hi,l,r);
  return {max(p1.first,p2.first),min(p1.second,p2.second)};
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++)cin>>b[i];
   build(1,1,n);
   ///cout<<query(1,1,n,4,5).first<<" "<<query(1,1,n,4,5).first<<endl;
   long a,b;
  for(int i=1;i<=n;i++)
  {
    pair<int,int>p;
    lo=i;
    hi=n;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      p=query(1,1,n,i,md);
      if(p.first<p.second)lo=md;
      else hi=md;
    }
    long id1=-1;
    for(long j=lo;j<=hi;j++)
    {
      p=query(1,1,n,i,j);
      if(p.first==p.second)
      {
        id1=i;
        break;
      }
    }
    ///cout<<id1<<endl;
    if(id1==-1)continue;
    lo=i;
    hi=n;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      p=query(1,1,n,i,md);
      if(p.first<=p.second)lo=md;
      else hi=md;
    }
    long id2;
    for(long j=hi;j>=lo;j--)
    {
      p=query(1,1,n,i,j);
      if(p.first==p.second)
      {
        id2=i;
        break;
      }
    }
    ///if(i==4)cout<<id2<<endl;
    long xx=id2-id1+1;
    ans+=((xx*(xx+1))/2);
  }
  cout<<ans<<endl;
  return 0;
}