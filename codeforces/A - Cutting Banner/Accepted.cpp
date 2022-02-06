/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/15/2019 22:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/538/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   string aa="CODEFORCES";
   string s;cin>>s;
  for(int i=0;i<s.size();i++)
  {
    for(int j=i;j<s.size();j++)
    {
      string bb;
      for(int k=0;k<s.size();k++)
      {
        if(k<i||k>j)bb.push_back(s[k]);
      }
      if(aa==bb)cout<<"YES"<<endl,exit(0);
    }
  }
  cout<<"NO"<<endl;
  return 0;
}