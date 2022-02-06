/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/20/2019 15:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3700 KB                              
*  problem: https://codeforces.com/contest/616/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string a,b;cin>>a>>b;
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  while(a.size())
  {
    if(a.back()=='0')a.pop_back();
    else break;
  }
  while(b.size())
  {
    if(b.back()=='0')b.pop_back();
    else break;
  }
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
   if(a.size()>b.size())cout<<'>'<<endl,exit(0);
  if(a.size()<b.size())cout<<'<'<<endl,exit(0);
  if(a==b)cout<<'='<<endl,exit(0);
  if(a>b)cout<<'>'<<endl,exit(0);
  cout<<'<'<<endl;
   return 0;
}