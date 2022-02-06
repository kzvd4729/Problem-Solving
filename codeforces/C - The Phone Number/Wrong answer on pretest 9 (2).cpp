/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/08/2018 21:46                        
*  solution_verdict: Wrong answer on pretest 9               language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/1017/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,arr[N+2],now;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i+=2)
  {
    if(i+1<=n)cout<<i+1<<" ";
    cout<<i<<" ";
  }
  cout<<endl;
  return 0;
}