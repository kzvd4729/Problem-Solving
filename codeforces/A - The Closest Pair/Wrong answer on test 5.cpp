/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/15/2018 16:24                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/311/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k;cin>>n>>k;
  if(k>(n*(n-1))/2)cout<<"no solution"<<endl,exit(0);
   int x=0,y=-1e9;
  while(n--)
  {
    cout<<x<<" "<<y<<endl;
    x++;y+=1e6;
  }
  return 0;
}