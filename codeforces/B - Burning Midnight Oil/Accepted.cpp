/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/19/2018 17:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/165/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
long pw[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,k;cin>>n>>k;
  pw[0]=1;int p=1;
  while(true)
  {
    pw[p]=pw[p-1]*k;
    if(pw[p]>1e9)break;
    else p++;
  }
  long lo=1,hi=1e9,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    long sum=0;
    for(int i=0;i<=p;i++)
      sum+=md/pw[i];
    if(sum>=n)hi=md;
    else lo=md;
  }
  for(md=lo;md<=hi;md++)
  {
    long sum=0;
    for(int i=0;i<=p;i++)
      sum+=md/pw[i];
    if(sum>=n)
      cout<<md<<endl,exit(0);
  }
  return 0;
}