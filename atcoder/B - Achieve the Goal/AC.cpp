/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-12 18:03:55                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc151/tasks/abc151_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k,m;cin>>n>>k>>m;
  int sm=0;
  for(int i=1;i<n;i++)cin>>aa[i],sm+=aa[i];
   int nd=n*m;
  int ans=nd-sm;
   if(ans>k)cout<<-1<<endl,exit(0);
   cout<<max(ans,0)<<endl;
    return 0;
}