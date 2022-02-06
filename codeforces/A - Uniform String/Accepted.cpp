/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/18/2018 20:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1092/problem/A
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
    int n,k;cin>>n>>k;
    int c=0;string s;
    while(n--)
    {
      s.push_back(char(c+'a'));
      c++;c%=k;
    }
    cout<<s<<endl;
  }
  return 0;
}