/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/02/2019 15:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 60 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/27/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;set<int>st;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;st.insert(x);
  }
  for(int i=1; ;i++)
  {
    if(st.find(i)==st.end())
      cout<<i<<endl,exit(0);
  }
  return 0;
}