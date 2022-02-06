/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/12/2018 00:43                        
*  solution_verdict: Wrong answer on test 13                 language: GNU C++14                               
*  run_time: 170 ms                                          memory_used: 9600 KB                              
*  problem: https://codeforces.com/contest/721/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5,inf=2e9;
long arr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,k,x;cin>>n>>k>>x;
  set<pair<long,long> >ps,ng;
  for(long i=1;i<=n;i++)
  {
    long t;cin>>t;
    if(t<0)ng.insert({-t,i});
    else ps.insert({t,i});
  }
  while(k--)
  {
    pair<long,long>p1={inf,1},p2={inf,1};
    if(ps.size())p1=*ps.begin();
    if(ng.size())p2=*ng.begin();
     if(ng.size()%2==0)
    {
      if(p1.first<p2.first)
      {
        ps.erase(p1);p1.first-=x;
        if(p1.first<0)ng.insert({-p1.first,p1.second});
        else ps.insert(p1);
        if(p2.first<inf)ng.insert(p2);
      }
      else
      {
        ng.erase(p2);p2.first-=x;
        if(p2.first<0)ps.insert({-p2.first,p2.second});
        else ng.insert(p2);
        if(p1.first<inf)ps.insert(p1);
      }
    }
    else
    {
      if(p1.first<p2.first)
      {
        ps.erase(p1);
        ps.insert({p1.first+x,p1.second});
        if(p2.first<inf)ng.insert(p2);
      }
      else
      {
        ng.erase(p2);
        ng.insert({p2.first+x,p2.second});
        if(p1.first<inf)ps.insert(p1);
      }
    }
  }
  while(ps.size())
  {
    arr[ps.begin()->second]=ps.begin()->first;
    ps.erase(*ps.begin());
  }
  while(ng.size())
  {
    arr[ng.begin()->second]=-ng.begin()->first;
    ng.erase(*ng.begin());
  }
  for(long i=1;i<=n;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
  return 0;
}