/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/28/2019 20:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1107/problem/B
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
    long n,k;cin>>n>>k;
    cout<<k+(n-1)*9LL<<endl;
  }
  return 0;
}