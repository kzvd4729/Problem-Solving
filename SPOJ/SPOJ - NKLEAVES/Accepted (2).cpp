/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-19 01:04:17                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 240                                        memory_used (MB): 133.1                           
*  problem: https://vjudge.net/problem/SPOJ-NKLEAVES
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
const long inf=1e17;
long dp[N+2][12],aa[N+2],qm[N+2],zic[N+2];

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
    assert(!empty());
    auto l=*lower_bound(x);
    return -(l.k*x+l.m);//for min return -;
  }
};

long get(long i,long j)
{
  long ret=zic[j]-zic[i];
  return ret-i*(qm[j]-qm[i]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,k;cin>>n>>k;
  for(long i=1;i<=n;i++)cin>>aa[i];
  for(long i=1;i<=n;i++)qm[i]=qm[i-1]+aa[i];
  for(long i=1;i<=n;i++)zic[i]=zic[i-1]+aa[i]*i;
  for(long i=0;i<=n+1;i++)
    for(long j=0;j<=k;j++)
      dp[i][j]=inf;
  dp[n+1][0]=0;
  for(long j=1;j<=k;j++)
  {
    lineContainer hl;//hl.add(0,0);
    for(long i=n;i>=1;i--)
    {
      hl.add(-qm[i],zic[i]+dp[i+1][j-1]);
      dp[i][j]=i*qm[i]-zic[i]+hl.get(i);
      //cout<<"**"<<dp[i][j]<<endl;
    }
  }
  cout<<dp[1][k]<<endl;
  return 0;
}