/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/16/2018 20:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/265/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int id;
string s,t;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   id=1;
  cin>>s>>t;
  for(auto x:t)
    if(x==s[id-1])id++;
  cout<<min(id,(int)s.size())<<endl;
  return 0;
}