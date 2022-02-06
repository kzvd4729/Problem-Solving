/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/29/2018 14:13                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/618/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;stack<int>st;
  for(int i=1;i<=n;i++)
  {
    st.push(1);
    while(st.size()>1)
    {
      int a=st.top();st.pop();
      int b=st.top();
      if(a==b)
      {
        st.pop();st.push(a+1);
      }
      else
      {
        st.push(a);
        break;
      }
    }
  }
  vector<int>v;
  while(st.size())
  {
    v.push_back(st.top());st.pop();
  }
  reverse(v.begin(),v.end());
  for(auto x:v)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}