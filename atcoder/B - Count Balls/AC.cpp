/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-07 23:22:25                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc158/tasks/abc158_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2],cc[N+2],dd[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,a,b;cin>>n>>a>>b;
   cout<<(n/(a+b))*a+min(a,n%(a+b))<<"\n";
    return 0;
}