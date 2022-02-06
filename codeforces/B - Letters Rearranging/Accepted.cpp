/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/15/2018 20:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1093/problem/B
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
    string s;cin>>s;
    sort(s.begin(),s.end());
    if(s[0]==s.back())cout<<-1<<"\n";
    else cout<<s<<"\n";
  }
  return 0;
}