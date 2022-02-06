/****************************************************************************************
*  @author: kzvd4729                                         created: May/15/2018 20:50                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 3500 KB                              
*  problem: https://codeforces.com/contest/984/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,x;
set<pair<int,int> >st;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    st.insert({x,i});
  }
  for(int i=1;i<n;i++)
  {
    if(i%2==1)
      st.erase(*st.rbegin());
    else st.erase(*st.begin());
  }
  cout<<st.begin()->first<<endl;
  return 0;
}