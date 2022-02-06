/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/23/2018 13:23                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/697/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,x,s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>t>>s>>x;
   int tmp=x-t;
   if(tmp==0)cout<<"YES"<<endl,exit(0);
   if(tmp<=1)cout<<"NO"<<endl,exit(0);
  if(tmp%s==0||tmp%s==1)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
   return 0;
}