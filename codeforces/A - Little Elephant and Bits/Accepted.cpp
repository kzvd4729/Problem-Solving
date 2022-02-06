/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/15/2020 10:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/258/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;
   for(int i=0;i<s.size()-1;i++)
  {
    if(s[i]=='0'&&s[i+1]=='1')
    {
      s.erase(s.begin()+i);
      cout<<s<<endl,exit(0);
    }
  }
  s.pop_back();cout<<s<<endl;
   return 0;
}