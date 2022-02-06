/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/20/2018 14:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/765/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  if(n%2==0)cout<<"home"<<endl;
  else cout<<"contest"<<endl;
   return 0;
}