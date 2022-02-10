/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-19 18:43:05                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 10                                         memory_used (MB): 16.4                            
*  problem: https://vjudge.net/problem/SPOJ-ACQUIRE
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<pair<int,int> >v(n),u;
  for(int i=0;i<n;i++)
    cin>>v[i].first>>v[i].second;
  sort(v.begin(),v.end());
  for(auto x:v)
  {
    while(u.size())
    {
      if(u.back().second<=x.second)
        u.pop_back();
      else break;
    }
    u.push_back(x);
  }
  lineContainer hl;long now=0;
  for(auto x:u)
  {
    hl.add(x.second,now);
    now=hl.get(x.first);
  }
  cout<<now<<"\n";
  return 0;
}