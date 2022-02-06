/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/01/2019 20:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1245/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int a,b;cin>>a>>b;
    if(__gcd(a,b)==1)cout<<"Finite\n";
    else cout<<"Infinite\n";
  }
    return 0;
}