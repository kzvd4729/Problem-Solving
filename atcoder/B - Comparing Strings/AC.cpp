/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-19 17:52:42                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc152/tasks/abc152_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int a,b;cin>>a>>b;
  string aa,bb;
  for(int i=1;i<=b;i++)
    aa.push_back(a+'0');
  for(int i=1;i<=a;i++)
    bb.push_back(b+'0');
   cout<<min(aa,bb)<<endl;
    return 0;
}