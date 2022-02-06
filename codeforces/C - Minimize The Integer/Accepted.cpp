/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/24/2019 21:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1500 KB                              
*  problem: https://codeforces.com/contest/1251/problem/C
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
    string s,od,ev;
    cin>>s;od.clear(),ev.clear();
    for(auto x:s)
    {
      if(((int)(x-'0'))%2)ev.push_back(x);
      else od.push_back(x);
    }
    merge(od.begin(),od.end(),ev.begin(),ev.end(),s.begin());
    cout<<s<<"\n";
  }
  return 0;
}