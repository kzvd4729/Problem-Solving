/****************************************************************************************
*  @author: kzvd4729                                         created: May/14/2018 20:39                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/979/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  if(n==0)cout<<0<<endl,exit(0);
  n++;
  if(n%2==0)cout<<n/2<<endl;
  else cout<<n<<endl;
   return 0;
}