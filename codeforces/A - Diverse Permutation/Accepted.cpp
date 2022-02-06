/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/13/2018 17:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/482/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  int lt=1,rt=n,turn=1;
  while(k--)
  {
    if(turn)
    {
      cout<<lt++<<" ";
      turn^=1;
    }
    else
    {
      cout<<rt--<<" ";
      turn^=1;
    }
  }
  if(turn)
  {
    for(int i=rt;i>=lt;i--)
      cout<<i<<" ";
  }
  else
  {
    for(int i=lt;i<=rt;i++)
      cout<<i<<" ";
  }
  cout<<endl;
  return 0;
}