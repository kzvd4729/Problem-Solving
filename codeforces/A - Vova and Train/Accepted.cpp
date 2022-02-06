/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/12/2018 20:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1066/problem/A
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
    int n,v,l,r;cin>>n>>v>>l>>r;
    cout<<n/v-r/v+(l-1)/v<<endl;
  }
  return 0;
}