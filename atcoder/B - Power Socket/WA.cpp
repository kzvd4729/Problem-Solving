/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-09-01 18:12:59                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc139/tasks/abc139_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b;cin>>a>>b;
  cout<<(b+a-1)/a<<endl;
  return 0;
}