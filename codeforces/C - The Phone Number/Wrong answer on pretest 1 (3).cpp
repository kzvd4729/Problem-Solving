/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/08/2018 21:21                        
*  solution_verdict: Wrong answer on pretest 1               language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1017/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=(n+1)/2;i<=n;i++)
    cout<<i<<" ";
  for(int i=1;i<(n+1)/2;i++)
    cout<<i<<" ";
  cout<<endl;
   return 0;
}