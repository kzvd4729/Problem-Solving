/****************************************************************************************
*  @author: kzvd4729                                         created: May/17/2019 16:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/785/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m;cin>>n>>m;
  if(m>=n)cout<<n<<endl,exit(0);
  long lo=1,hi=2e9,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    long x=(md*(md-1))/2+md+m;
    if(x>=n)hi=md;else lo=md;
  }
  for(md=lo;md<=hi;md++)
    if((md*(md-1))/2+md+m>=n)cout<<m+md<<endl,exit(0);
  cout<<m<<endl;
  return 0;
}