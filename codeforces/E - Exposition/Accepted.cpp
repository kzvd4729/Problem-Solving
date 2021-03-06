/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/06/2018 19:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 483 ms                                          memory_used: 5400 KB                              
*  problem: https://codeforces.com/contest/6/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2];
pair<int,int>seg[5*N+2];
void build(int node,int lo,int hi)
{
  if(lo==hi)
  {
    seg[node]={aa[lo],aa[hi]};
    return ;
  }
  int md=(lo+hi)/2;
  build(node*2,lo,md);
  build(node*2+1,md+1,hi);
  seg[node].first=min(seg[node*2].first,seg[node*2+1].first);
  seg[node].second=max(seg[node*2].second,seg[node*2+1].second);
}
pair<int,int>qry(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return {1e9,-1e9};
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  pair<int,int>p1=qry(node*2,lo,md,lt,rt);
  pair<int,int>p2=qry(node*2+1,md+1,hi,lt,rt);
  return {min(p1.first,p2.first),max(p1.second,p2.second)};
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  build(1,1,n);vector<pair<int,int> >pr;int mx=0;
    pair<int,int>p;
  for(int i=1;i<=n;i++)
  {
    int lo=i,hi=n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      p=qry(1,1,n,i,md);
      if(p.second-p.first>k)hi=md;
      else lo=md;
    }
    for(md=hi;md>=lo;md--)
    {
      p=qry(1,1,n,i,md);
      if(p.second-p.first<=k)break;
    }
    int now=md-i+1;
    if(now==mx)
      pr.push_back({i,md});
    if(now>mx)
    {
      mx=now;pr.clear();
      pr.push_back({i,md});
    }
  }
  cout<<mx<<" "<<pr.size()<<"\n";
  for(auto x:pr)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}