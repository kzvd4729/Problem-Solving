/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/13/2019 22:41                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1257/problem/A
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
    int n,x,a,b;cin>>n>>x>>a>>b;
    int mx=n-1;
     cout<<min(abs(a-b)+x,mx)<<"\n";
   }
  return 0;
}