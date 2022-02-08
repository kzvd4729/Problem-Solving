/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-19 18:03:45                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 2 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc143/tasks/abc143_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int a,b;cin>>a>>b;
  cout<<max(0,a-2*b)<<endl;
   return 0;
}