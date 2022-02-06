/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/22/2019 21:20                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1140/problem/B
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
    int n;cin>>n;string s;cin>>s;
    if(s[0]=='>'||s[n-1]=='<')
      cout<<0<<"\n";
    else cout<<1<<"\n";
  }
  return 0;
}