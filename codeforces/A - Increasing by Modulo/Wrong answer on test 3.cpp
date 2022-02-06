/****************************************************************************************
*  @author: kzvd4729                                         created: May/29/2019 18:55                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1168/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],n,m;
bool ck(int md)
{
  int ls=0;
  for(int i=1;i<=n;i++)
  {
    if(aa[i]<ls)
    {
      if(ls-aa[i]>md)return false;
    }
    else
    {
      int rq=m-1-aa[i]+ls;
      if(rq>md)ls=aa[i];
    }
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  int lo=0,hi=m-1,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(ck(md))hi=md;
    else lo=md;
  }
  for(md=lo;md<=hi;md++)
    if(ck(md))cout<<md<<endl,exit(0);
  assert(0);
  return 0;
}