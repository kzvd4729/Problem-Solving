/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/25/2018 01:06                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/49/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=2;i<=n;i++)
    cout<<i<<" ";
  cout<<1<<endl;
   return 0;
}