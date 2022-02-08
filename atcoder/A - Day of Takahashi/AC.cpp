/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-05 18:02:50                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc096/tasks/abc096_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int a,b,ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>a>>b;
  if(b>=a)cout<<a<<endl;
  else cout<<a-1<<endl;
   return 0;
}