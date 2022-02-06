/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/16/2019 19:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1174/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n+n;i++)cin>>aa[i];
  sort(aa+1,aa+n+n+1);
  int sm=0,ms=0;
  for(int i=1;i<=n;i++)sm+=aa[i];
  for(int i=n+1;i<=n+n;i++)ms+=aa[i];
  if(sm==ms)cout<<-1<<endl,exit(0);
  for(int i=1;i<=n+n;i++)
    cout<<aa[i]<<" ";
  cout<<endl;
  return 0;
}