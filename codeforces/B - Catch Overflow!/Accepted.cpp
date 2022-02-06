/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/17/2019 18:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 2200 KB                              
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
  stack<long>st;multiset<long>mst;
  while(n--)
  {
    string s;cin>>s;
    if(s=="add")
    {
      long ml=1;
      for(auto x:mst)
      {
        ml*=x;
        if(ml>=rn)cout<<"OVERFLOW!!!"<<endl,exit(0);
      }
      add+=ml;
      if(add>=rn)cout<<"OVERFLOW!!!"<<endl,exit(0);
    }
    else if(s=="for")
    {
      long x;cin>>x;
      st.push(x);if(x>1)mst.insert(x);
    }
    else
    {
      if(st.top()>1)mst.erase(mst.find(st.top()));
      st.pop();
    }
  }
  cout<<add<<endl;
  return 0;
}