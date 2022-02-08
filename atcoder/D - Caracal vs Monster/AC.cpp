/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-26 18:09:12                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc153/tasks/abc153_d
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
long dfs(long n)
{
  if(n==0)return 0;
  return 1+2*dfs(n/2);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;cout<<dfs(n)<<endl;
     return 0;
}