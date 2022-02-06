/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/19/2019 22:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1118/problem/D2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  sort(aa+1,aa+n+1,greater<int>());
  int lo=1,hi=n,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    long tt=0;
    for(int i=1;i<=n;i++)
      tt+=max(0,aa[i]-((i-1)/md))*1LL;
    if(tt>=k)hi=md;
    else lo=md;
  }
  for(md=lo;md<=hi;md++)
  {
    long tt=0;
    for(int i=1;i<=n;i++)
      tt+=max(0,aa[i]-((i-1)/md))*1LL;
    if(tt>=k)cout<<md<<endl,exit(0);
  }
  cout<<-1<<endl;
  return 0;
}