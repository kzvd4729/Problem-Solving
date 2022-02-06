/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/05/2019 21:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1132/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b,c,d;cin>>a>>b>>c>>d;
   if(!a&&c)cout<<0<<endl,exit(0);
  if(a==d)cout<<1<<endl,exit(0);
  cout<<0<<endl;
   return 0;
}