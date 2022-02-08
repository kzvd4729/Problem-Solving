/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-07 23:35:01                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 37 ms                                           memory_used: 976 KB                               
*  problem: https://atcoder.jp/contests/abc158/tasks/abc158_d
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2],cc[N+2],dd[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  deque<char>dq;string s;cin>>s;
  for(int i=0;i<s.size();i++)dq.push_back(s[i]);
   int f=0,q;cin>>q;
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==1)f^=1;
    else
    {
      char c;cin>>ty>>c;
      if(ty==1)
      {
        if(!f)dq.push_front(c);
        else dq.push_back(c);
      }
      else
      {
        if(f)dq.push_front(c);
        else dq.push_back(c); 
      }
    }
  }
  while(dq.size())
  {
    if(!f)
    {
      cout<<dq.front();dq.pop_front();
    }
    else
    {
      cout<<dq.back();dq.pop_back(); 
    }
  }
  cout<<"\n";
  return 0;
}