/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-05 18:05:42                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 2 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc104/tasks/abc104_a
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   int n;cin>>n;
  if(n<1200)cout<<"ABC"<<endl;
  else if(n<2800)cout<<"ARC"<<endl;
  else cout<<"AGC"<<endl;
  return 0;
}