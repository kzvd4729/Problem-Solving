/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-26 18:05:42                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 34 ms                                           memory_used: 1024 KB                              
*  problem: https://atcoder.jp/contests/abc153/tasks/abc153_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>aa[i];
  sort(aa+1,aa+n+1);
    long sm=0;
  for(int i=1;i<=n-k;i++)sm+=aa[i];
  cout<<sm<<endl;
    return 0;
}