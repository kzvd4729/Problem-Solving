/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2018 22:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/959/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  if(n%2==0)cout<<"Mahmoud"<<endl;
  else cout<<"Ehab"<<endl;
   return 0;
}