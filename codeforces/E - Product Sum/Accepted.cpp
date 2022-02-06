/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/19/2019 02:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 33700 KB                             
*  problem: https://codeforces.com/contest/631/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
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
    return (l.k*x+l.m);//for min return -;
  }
};
long aa[N+2],qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=1;i<=n;i++)cin>>aa[i];
  for(long i=1;i<=n;i++)qm[i]=qm[i-1]+aa[i];
   lineContainer hl;long mx=-inf;
  for(long i=n;i>=1;i--)
  {
    hl.add(i,qm[n]-qm[i]);
    mx=max(mx,hl.get(aa[i])-qm[n]+qm[i-1]-(i-1)*aa[i]);
  }
  lineContainer lh;
  for(long i=1;i<=n;i++)
  {
    lh.add(i-1,qm[n]-qm[i-1]);
    mx=max(mx,lh.get(aa[i])-qm[n]+qm[i-1]-(i-1)*aa[i]);
  }
  for(long i=1;i<=n;i++)mx+=aa[i]*i;
  cout<<mx<<endl;
  return 0;
}