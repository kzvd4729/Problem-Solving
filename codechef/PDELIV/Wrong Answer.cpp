/****************************************************************************************
*  @author: kzvd4729                                         created: 19-07-2019 13:53:35                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 1.26 sec                                        memory_used: 293.4M                               
*  problem: https://www.codechef.com/problems/PDELIV
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
long pp[N+2],aa[N+2],hh[N+2];
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
lineContainer seg[5*N+2];
void add(int node,int lo,int hi,int id,long m,long b)
{
  seg[node].add(m,b);
  if(lo==hi)return ;
  int md=(lo+hi)/2;
  if(id<=md)add(node*2,lo,md,id,m,b);
  else add(node*2+1,md+1,hi,id,m,b);
}
long get(int node,int lo,int hi,int lt,int rt,long x)
{
  if(lo>rt||hi<lt)return inf;
  if(lo>=lt&&hi<=rt)return seg[node].get(x);
  int md=(lo+hi)/2;
  long p1=get(node*2,lo,md,lt,rt,x);
  long p2=get(node*2+1,md+1,hi,lt,rt,x);
  return min(p1,p2);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    long s,p;cin>>s>>p;
    add(1,1,n,i,-2*s,s*s+p);
  }
  for(int i=1;i<=m;i++)
  {
    long c,k;cin>>c>>k;
    vector<long>v;v.push_back(0);
    while(k--)
    {
      long x;cin>>x;
      v.push_back(x);
    }
    v.push_back(n+1);
    sort(v.begin(),v.end());
    long mn=inf;
    for(int i=0;i<v.size()-1;i++)
    {
      if(v[i]+1<=v[i+1]-1)
        mn=min(mn,get(1,1,n,v[i]+1,v[i+1]-1,c)+c*c);
    }
    cout<<mn<<"\n";
  }
  return 0;
}