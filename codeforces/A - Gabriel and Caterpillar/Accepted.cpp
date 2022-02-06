/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/08/2019 12:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/652/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long h1,h2,a,b;cin>>h1>>h2;cin>>a>>b;
  h1+=a*8;
  if(h1>=h2)cout<<0<<endl,exit(0);
  for(long i=1;i<=N;i++)
  {
    h1-=12*b;h1+=12*a;
    if(h1>=h2)cout<<i<<endl,exit(0);
  }
  cout<<-1<<endl;
  return 0;
}