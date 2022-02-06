/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/05/2019 13:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1097/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;
  for(int i=1;i<=5;i++)
  {
    string x;cin>>x;
    if(x[0]==s[0]||x[1]==s[1])cout<<"YES"<<endl,exit(0);
  }
  cout<<"NO"<<endl;
  return 0;
}