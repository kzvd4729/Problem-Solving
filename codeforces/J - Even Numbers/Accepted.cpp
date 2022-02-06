/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/24/2019 01:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 374 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/101972/problem/J
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long n;cin>>n;
    long x=__builtin_popcountll(n);
    cout<<n-((1LL<<x)-1)<<endl;
  }
  return 0;
}