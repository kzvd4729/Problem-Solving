/****************************************************************************************
*  @author: kzvd4729                                         created: 18-07-2019 20:56:04                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 22.6M                                
*  problem: https://www.codechef.com/problems/CCC
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const long inf=1e18;
long aa[N+2],dp[N+2][N+2];
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
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)
      cin>>aa[i];
    sort(aa+1,aa+n+1);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=k;j++)
        dp[i][j]=inf;
    for(int i=n;i>=1;i--)
      dp[i][1]=aa[i]*(n-i+1);
    for(int j=2;j<=k;j++)
    {
      lineContainer hl;
      hl.add(0,0);
      for(int i=n;i>=1;i--)
      {
        dp[i][j]=hl.get(aa[i])-(aa[i]*i);
        hl.add(i,dp[i][j-1]);
      }
    }
    long ans=inf;
    for(int i=1;i<=n;i++)
      ans=min(ans,dp[i][k]);
    cout<<ans<<"\n";
  }
  return 0;
}