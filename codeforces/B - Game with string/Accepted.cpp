/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/22/2019 20:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/1104/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;stack<char>st;int cnt=0;
  for(auto x:s)
  {
    if(st.size()==0)
      st.push(x);
    else
    {
      if(st.top()==x)
      {
        cnt++;st.pop();
      }
      else st.push(x);
    }
  }
  if(cnt%2)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}