/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/23/2018 19:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/703/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,a,b,m,c;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a>>b;
    if(a>b)m++;
    if(b>a)c++;
  }
  if(m>c)cout<<"Mishka"<<endl,exit(0);
  if(c>m)cout<<"Chris"<<endl,exit(0);
  cout<<"Friendship is magic!^^"<<endl;
  return 0;
}