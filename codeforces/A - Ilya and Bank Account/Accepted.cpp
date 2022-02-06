/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/15/2018 00:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 60 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/313/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;
  if(s[0]!='-')cout<<s<<endl,exit(0);
   int n=s.size()-1;
  if(s[n]>s[n-1])s.erase(s.begin()+n);
  else s.erase(s.begin()+n-1);
   if(s.size()==2&&s[1]=='0')s.erase(s.begin()+0);
  cout<<s<<endl;
   return 0;
}