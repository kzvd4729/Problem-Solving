/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/08/2019 20:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1238/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long x,y;cin>>x>>y;
    if(x-y==1)cout<<"NO\n";
    else cout<<"YES\n";
  }
  return 0;
}