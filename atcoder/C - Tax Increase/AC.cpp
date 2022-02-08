/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-07 23:28:07                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 10 ms                                           memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc158/tasks/abc158_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2],cc[N+2],dd[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b;cin>>a>>b;
  for(int i=1;i<=1000000;i++)
  {
    int ta=floor((i*8.0)/(100.0));
    int tb=floor((i*10.0)/(100.0));
     //cout<<ta<<" "<<tb<<endl;
     if(ta==a&&tb==b)cout<<i<<endl,exit(0);
  }
  cout<<-1<<endl;
  return 0;
}