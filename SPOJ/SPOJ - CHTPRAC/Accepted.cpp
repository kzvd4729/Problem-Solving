/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-18 21:14:50                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 80                                         memory_used (MB): 47.1                            
*  problem: https://vjudge.net/problem/SPOJ-CHTPRAC
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long vv[N+2],dis[N+2],lst[N+2];

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
  void add(long k,long m,int ml)
  {
    k*=ml;m*=ml;//for min
    auto z=insert({k,m,0}),y=z++,x=y;
    while(isect(y,z))z=erase(z);
    if(x!=begin()&&isect(--x,y))isect(x,y=erase(y));
    while((y=x)!=begin()&&(--x)->p>=y->p)
      isect(x,erase(y));
  }
  long get(long x,int ml)
  {
    assert(!empty());
    auto l=*lower_bound(x);
    return ml*(l.k*x+l.m);//for min return -;
  }
};
long aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,ty;cin>>n>>ty;ty=(ty%2?-1:1);
  lineContainer hl;
  for(int i=1;i<=n;i++)
  {
    int c;cin>>c;
    if(c==1)
    {
      int m,b;cin>>m>>b;
      hl.add(m,b,ty);
    }
    else 
    {
      int x;cin>>x;
      cout<<hl.get(x,ty)<<"\n";
    }
  }
  return 0;
}