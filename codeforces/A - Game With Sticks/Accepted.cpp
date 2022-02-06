/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/19/2018 16:50                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/451/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,m;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  int x=min(n,m);
  if(x%2)cout<<"Akshat"<<endl;
  else cout<<"Malvika"<<endl;
   return 0;
}