/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-07-18 17:40:06                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1760                                       memory_used (MB): 70.7                            
*  problem: https://vjudge.net/problem/SPOJ-APIO10A
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#include<bits/stdc++.h>
#define endl '\n'
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

int aa[N+2],qm[N+2];
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t;//cin>>t;
  scanf("%d",&t);
  while(t--)
  {
    int n,a,b,c;//cin>>n>>a>>b>>c;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    for(int i=1;i<=n;i++)scanf("%d",&aa[i]),qm[i]=qm[i-1]+aa[i];

    lineContainer st;
    st.add(0,c);long ans;
    for(int i=1;i<=n;i++)
    {
      ans=st.get(qm[i])+1LL*a*qm[i]*qm[i]+1LL*b*qm[i];
      st.add(-2LL*a*qm[i],ans+1LL*a*qm[i]*qm[i]-1LL*b*qm[i]+c);
    }
    printf("%lld\n",ans);
  }
  return 0;
}