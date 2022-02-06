/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/02/2018 00:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/148/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int aa[20];set<int>st;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   for(int i=1;i<=4;i++)cin>>aa[i];
  int n;cin>>n;
  for(int i=1;i<=4;i++)
  {
    for(int j=aa[i];j<=n;j+=aa[i])
      st.insert(j);
  }
  cout<<st.size()<<endl;
  return 0;
}