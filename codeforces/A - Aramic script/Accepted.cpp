/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/23/2018 18:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/975/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;set<string>st;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());
    st.insert(s);
  }
  cout<<st.size()<<endl;
  return 0;
}