/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/20/2019 10:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 343 ms                                          memory_used: 68500 KB                             
*  problem: https://codeforces.com/contest/455/problem/E
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
  //for doubles, use inf=1/.0,div(a,b)=a/b)
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
    k*=-1,m*=-1;//for min;
    auto z=insert({k,m,0}),y=z++,x=y;
    while(isect(y,z))z=erase(z);
    if(x!=begin()&&isect(--x,y))isect(x,y=erase(y));
    while((y=x)!=begin()&&(--x)->p>=y->p)
      isect(x,erase(y));
  }
  long get(long x)
  {
    //assert(!empty());
    if(empty())return inf;
    auto l=*lower_bound(x);
    return -(l.k*x+l.m);//-(l.k*x+l.m)for min;
  }
};
lineContainer bit[N+2];
long n,aa[N+2],qm[N+2],ans[N+2];
void add(int id,long m,long b)
{
  for( ;id>0;id-=id&-id)
    bit[id].add(m,b);
}
long get(int id,long x)
{
  //cout<<"*"<<id<<endl;
  long ret=LLONG_MAX;
  for( ;id<=n;id+=id&-id)
    ret=min(ret,bit[id].get(x));
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i],qm[i]=qm[i-1]+aa[i];
  int q;cin>>q;
  vector<vector<int> >qr(q);
  for(int i=0;i<q;i++)
  {
    qr[i].resize(3);
    cin>>qr[i][1]>>qr[i][0];qr[i][2]=i+1;
  }
  sort(qr.begin(),qr.end());
  int pt=1;
  for(auto x:qr)
  {
    while(pt<=x[0])
    {
      add(pt,aa[pt],-qm[pt-1]+(pt-1)*aa[pt]);
      pt++;
    }
    ans[x[2]]=get(max(x[0]-x[1]+1,1),x[1]-x[0])+qm[x[0]];
  }
  for(int i=1;i<=q;i++)
    cout<<ans[i]<<"\n";
  return 0;
}