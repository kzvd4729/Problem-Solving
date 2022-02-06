/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/12/2018 20:55                        
*  solution_verdict: Time limit exceeded on test 7           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1076/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=2;i<=1000000000;i++)
  {
    if(n%i==0)
    {
      long ans=1LL+(n-i)/2LL;
      cout<<ans<<endl;
      exit(0);
    }
  }
  return 0;
}