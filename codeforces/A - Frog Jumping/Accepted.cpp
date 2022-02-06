/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/16/2018 20:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1077/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long a,b,k;cin>>a>>b>>k;
    long rt=(k+1)/2;
    long lt=k-rt;
     cout<<rt*a-lt*b<<endl;
   }
  return 0;
}