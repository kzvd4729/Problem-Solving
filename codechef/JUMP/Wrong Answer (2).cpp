/****************************************************************************************
*  @author: kzvd4729                                         created: 19-07-2019 11:32:34                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/problems/JUMP
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int pp[N+2],aa[N+2],hh[N+2];
const long inf=1e17;
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
  //const long inf=LLONG_MAX;
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
    if(empty())return inf;
    auto l=*lower_bound(x);
    return -(l.k*x+l.m);//for min return -;
  }
};
lineContainer bit[N+2];
void add(int id,int n,long m,long b)
{
  for( ;id<=n;id+=id&-id)
    bit[id].add(m,b);
}
long get(int id,long x)
{
  long ret=inf;
  for( ;id>0;id-=id&-id)
    ret=min(ret,bit[id].get(x));
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>pp[i];
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=n;i++)cin>>hh[i];
  for(int i=1;i<=n;i++)add(i,n,0,0);
  long now=0;
  add(pp[1],n,-2*hh[1],hh[1]*hh[1]+now);
  for(int i=2;i<=n;i++)
  {
    now=get(pp[i],hh[i])+hh[i]*hh[i]+aa[i];
    //cout<<"*"<<now<<endl;
    add(pp[i],n,-2*hh[i],hh[i]*hh[i]+now);
  }
  cout<<now<<endl;
  return 0;
}