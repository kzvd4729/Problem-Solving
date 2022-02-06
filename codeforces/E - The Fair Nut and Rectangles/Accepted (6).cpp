/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/18/2019 15:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1528 ms                                         memory_used: 90300 KB                             
*  problem: https://codeforces.com/contest/1083/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
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
    auto z=insert({k,m,0}),y=z++,x=y;
    while(isect(y,z))z=erase(z);
    if(x!=begin()&&isect(--x,y))isect(x,y=erase(y));
    while((y=x)!=begin()&&(--x)->p>=y->p)
      isect(x,erase(y));
  }
  long getMax(long x)
  {
    assert(!empty());
    auto l=*lower_bound(x);
    return l.k*x+l.m;
  }
};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<vector<long> >v(n);
  for(int i=0;i<n;i++)
  {
    v[i].resize(3);
    for(int j=0;j<3;j++)
      cin>>v[i][j];
  }
  sort(v.begin(),v.end());
  lineContainer hl;hl.add(0,0);
  long ans=0;
  for(int i=0;i<n;i++)
  {
    long now=v[i][0]*v[i][1]-v[i][2]+hl.getMax(v[i][1]);
    hl.add(-v[i][0],now);ans=max(ans,now);
  }
  cout<<ans<<endl;
  return 0;
}