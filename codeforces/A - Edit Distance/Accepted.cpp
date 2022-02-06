/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/29/2019 12:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/102001/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int one=0,zero=0;
  for(auto x:s)x=='1'?one++:zero++;
   char c='0';if(zero>=one)c='1';
    string p;
  for(int i=1;i<=s.size();i++)p.push_back(c);
  if(one!=zero)cout<<p<<endl,exit(0);
  if(s[0]=='0')
  {
    cout<<'1';
    for(int i=2;i<=s.size();i++)cout<<'0';
  }
  else
  {
    cout<<'0';
    for(int i=2;i<=s.size();i++)cout<<'1';
  }
    return 0;
}