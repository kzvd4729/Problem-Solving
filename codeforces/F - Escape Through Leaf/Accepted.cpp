/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/19/2019 02:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 311 ms                                          memory_used: 102900 KB                            
*  problem: https://codeforces.com/contest/932/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long aa[N+2],bb[N+2],now,ans[N+2];
vector<long>adj[N+2];
vector<pair<long,long> >vc[N+2];
#pragma once
struct line
{
  mutable long k,m,p;
  bool operator<(const line& o)const{return k<o.k;}
  bool operator<(long x)const{return p<x;}
};
struct lineContainer:multiset<line,less<>>
{
  //(for doubles,use inf=1/.0,div(a,b)=a/b)
  const long inf=LLONG_MAX;
  long div(long a,long b){return a/b-((a^b)<0&&a%b);}
  bool isect(iterator x,iterator y)
  {
    if(y==end()){x->p=inf;return false;}
    if(x->k==y->k)x->p=x->m>y->m?inf:-inf;
    else x->p=div(y->m-x->m,x->k-y->k);
    return x->p>=y->p;
  }
  void add(long k,long m)
  {
    k*=-1;m*=-1;//for min
    auto z=insert({k,m,0}),y=z++,x=y;
    while(isect(y,z))z=erase(z);
    if(x!=begin()&&isect(--x,y))isect(x,y=erase(y));
    while((y=x)!=begin()&&(--x)->p>=y->p)
      isect(x,erase(y));
  }
  long get(long x)
  {
    assert(!empty());
    auto l=*lower_bound(x);
    return -(l.k*x+l.m);//for min return -;
  }
};
lineContainer hl[N+2];
long dfs(long node,long par)
{
  vector<long>v;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    v.push_back(dfs(x,node));
  }
  if(v.size()==0)
  {
    hl[node].add(bb[node],0);
    vc[node].push_back({bb[node],0});
    return node;
  }
  long mx=-1,nd;
  for(auto x:v)
    if(vc[x].size()>mx)mx=vc[x].size(),nd=x;
  for(auto x:v)
  {
    if(x==nd)continue;
    for(auto z:vc[x])
    {
      hl[nd].add(z.first,z.second);
      vc[nd].push_back(z);
    }
  }
  now=hl[nd].get(aa[node]);ans[node]=now;
  hl[nd].add(bb[node],now);
  vc[nd].push_back({bb[node],now});
  return nd;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=1;i<=n;i++)cin>>aa[i];
  for(long i=1;i<=n;i++)cin>>bb[i];
  for(long i=1;i<n;i++)
  {
    long u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,-1);
  for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}