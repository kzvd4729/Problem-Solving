/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/19/2019 01:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 1000 KB                              
*  problem: https://codeforces.com/contest/1220/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;char c='z'+1;
  for(auto x:s)
  {
    c=min(c,x);
    if(c==x)cout<<"Mike\n";
    else cout<<"Ann\n";
  }
  return 0;
}