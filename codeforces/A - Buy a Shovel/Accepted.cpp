/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/18/2018 17:39                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 30 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/732/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,r;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>r;
  for(int i=1;  ;i++)
  {
    if((i*n)%10==0||(i*n)%10==r)
    {
      cout<<i<<endl;
      return 0;
    }
  }
  return 0;
}