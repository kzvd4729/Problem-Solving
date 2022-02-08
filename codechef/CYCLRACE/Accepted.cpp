/****************************************************************************************
*  @author: kzvd4729                                         created: 18-07-2019 16:48:32                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.04 sec                                        memory_used: 48.5M                                
*  problem: https://www.codechef.com/problems/CYCLRACE
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
  void add(long k,long m)
  {
    //k*=-1;m*=-1;//for min
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
    return l.k*x+l.m;
    //return -(l.k*x+l.m);//for min
  }
};
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  lineContainer hl;hl.add(0,0);
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      long tim,cyc,nsp;cin>>tim>>cyc>>nsp;
      long con=dis[cyc]+vv[cyc]*(tim-lst[cyc]);
      hl.add(nsp,-(tim*nsp-con));
      dis[cyc]=con,lst[cyc]=tim,vv[cyc]=nsp;
    }
    else
    {
      int x;cin>>x;
      cout<<hl.get(x)<<"\n";
    }
  }
  return 0;
}