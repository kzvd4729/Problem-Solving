/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-09-01 18:27:43                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc139/tasks/abc139_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b;cin>>a>>b;
  if(b==1)cout<<0<<endl,exit(0);
   int cnt=1;
  for(int i=1; ;i++)
  {
    cnt+=(a-1);
    if(cnt>=b)cout<<i<<endl,exit(0);
  }
  return 0;
}