/****************************************************************************************
*  @author: kzvd4729                                         created: May/09/2019 21:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1163/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  if(m==0)cout<<1<<endl,exit(0);
  if(m<=n/2)
    cout<<m<<endl;
  else cout<<n-m<<endl;
  return 0;
}