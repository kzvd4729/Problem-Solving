/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/25/2018 22:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/723/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int a,b,c;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>a>>b>>c;
   if(b>a)swap(a,b);
  if(c>a)swap(a,c);
  if(c>b)swap(b,c);
   cout<<abs(a-b)+abs(b-c)<<endl;
   return 0;
}