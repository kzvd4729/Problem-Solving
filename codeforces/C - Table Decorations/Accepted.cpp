/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/19/2018 19:03                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/478/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int a,b,c;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>a>>b>>c;
  int ans=0;
  if(b>a)swap(a,b);
  if(c>a)swap(a,c);
  if(c>b)swap(b,c);
   if((b*1LL+c*1LL)*2<=a*1LL)cout<<b*1LL+c*1LL<<endl,exit(0);
   else cout<<(a*1LL+b*1LL+c*1LL)/3<<endl;
   return 0;
}