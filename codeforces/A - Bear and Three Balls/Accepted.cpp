/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/17/2018 00:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/653/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
int vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;vis[x]=1;
  }
  for(int i=1;i<=1000;i++)
  {
    if(vis[i]&&vis[i+1]&&vis[i+2])cout<<"YES"<<endl,exit(0);
  }
  cout<<"NO"<<endl,exit(0);
  return 0;
}