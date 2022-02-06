/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/16/2018 19:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/11/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long n;cin>>n;n=abs(n);
   long sum=0;
  for(long i=0; ;i++)
  {
    sum+=i;
    if(sum==n)
      cout<<i<<endl,exit(0);
    else if(sum>n)
    {
      if((sum-n)%2==0)
        cout<<i<<endl,exit(0);
    }
  }
  return 0;
}