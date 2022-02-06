/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/19/2019 18:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/609/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  sort(aa+1,aa+n+1);
  for(int i=n;i>=1;i--)
  {
    m-=aa[i];
    if(m<=0)cout<<n-i+1<<endl,exit(0);
  }
  return 0;
}