/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-10 18:07:34                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc150/tasks/abc150_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long a,b;cin>>a>>b;
  if(a*500>=b)cout<<"Yes\n";else cout<<"No\n";
    return 0;
}