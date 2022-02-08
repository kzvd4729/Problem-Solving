/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-17 18:47:07                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc091/tasks/abc091_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int a,b,c;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>a>>b>>c;
  if(a+b>=c)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
   return 0;
}