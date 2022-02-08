/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-09-01 18:22:42                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc139/tasks/abc139_d
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  cout<<(n*(n-1))/2<<endl;
  return 0;
}