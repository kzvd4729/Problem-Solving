/****************************************************************************************
*  @author: kzvd4729#                                        created: Oct/29/2018 22:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/622/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long n;cin>>n;
  for(long i=1; ;i++)
  {
    if(i>=n)cout<<n<<endl,exit(0);
    n-=i;
  }
  return 0;
}