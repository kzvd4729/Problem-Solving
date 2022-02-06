/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/20/2018 14:27                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/765/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;
  char last='a';
  for(auto x:s)
  {
    if(x<=last)continue;
    last++;
    if(last!=x)cout<<"NO"<<endl,exit(0);
  }
  cout<<"YES"<<endl;
  return 0;
}