/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/18/2018 22:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1054/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;int ok=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(x>ok)cout<<i<<endl,exit(0);
    if(x==ok)ok++;
  }
  cout<<-1<<endl;
  return 0;
}