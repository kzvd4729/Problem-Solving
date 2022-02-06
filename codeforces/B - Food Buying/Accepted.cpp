/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/04/2020 20:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1296/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long x;cin>>x;long sm=0;
    while(x>=10)
    {
      long m=x%10;long r=x-m;
      sm+=r;m+=r/10;x=m;
    }
    sm+=x;
    cout<<sm<<"\n";
  }
  return 0;
}