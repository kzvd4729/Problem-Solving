/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/28/2019 19:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1183/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
bool ok(int x)
{
  int sm=0;
  while(x)
  {
    sm+=x%10;x/=10;
  }
  return !(sm%4);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  while(true)
  {
    if(ok(n))cout<<n<<endl,exit(0);
    n++;
  }
  return 0;
}