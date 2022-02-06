/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/24/2019 21:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1130/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int ps=0,ng=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(x>0)ps++;if(x<0)ng++;
  }
  if(ps>=(n+1)/2)cout<<1<<endl,exit(0);
  if(ng>=(n+1)/2)cout<<-1<<endl,exit(0);
  cout<<0<<endl;
  return 0;
}