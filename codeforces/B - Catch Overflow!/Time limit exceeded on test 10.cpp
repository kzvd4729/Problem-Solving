/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/17/2019 17:53                        
*  solution_verdict: Time limit exceeded on test 10          language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 1500 KB                              
*  problem: https://codeforces.com/contest/1175/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
const long rn=(1LL<<32LL);
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;long add=0;
  stack<long>st;
  while(n--)
  {
    string s;cin>>s;
    if(s=="add")
    {
      vector<long>v;long ml=1;
      while(st.size())
      {
        v.push_back(st.top());
        ml*=st.top();
        if(ml>=rn)cout<<"OVERFLOW!!!"<<endl,exit(0);
        st.pop();
      }
      while(v.size())
      {
        st.push(v.back());
        v.pop_back();
      }
      add+=ml;
      if(add>=rn)cout<<"OVERFLOW!!!"<<endl,exit(0);
    }
    else if(s=="for")
    {
      long x;cin>>x;
      st.push(x);
    }
    else st.pop();
  }
  cout<<add<<endl;
  return 0;
}