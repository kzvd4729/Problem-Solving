/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/08/2018 16:54                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/689/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const int inf=INT_MAX;
int seg[4*N][2],n,a[N+2],b[N+2];
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
}
pair<int,int>query(int node,int lo,int hi,int l,int r)
{
  if(lo>r||hi<l)return {-inf,inf};
  if(lo>=l&&hi<=r)return {seg[node][0],seg[node][1]};
  int md=(lo+hi)/2;
  pair<int,int>p1=query(node*2,lo,md,l,r);
  pair<int,int>p2=query(node*2,md+1,hi,l,r);
  return {max(p1.first,p2.first),min(p1.second,p2.second)};
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++)cin>>b[i];
   for(int i=1;i<=n;i++)
  {
    pair<int,int>p;
    lo=i;
    hi=n;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      p=query(1,1,n,lo,md);
      if(p.first<p.second)lo=md;
      else hi=md;
    }
  }
  return 0;
}