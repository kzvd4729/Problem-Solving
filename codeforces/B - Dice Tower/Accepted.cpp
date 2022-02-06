/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/17/2019 21:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1266/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long n;cin>>n;
    if(n<14)
    {
      cout<<"NO\n";continue;
    }
    long x=n/14;long rm=n-x*14;
     if(rm>=1&&rm<=6)cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}