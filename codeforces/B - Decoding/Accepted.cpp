/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/10/2018 00:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/746/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n;
string s;
deque<char>dq;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>s;
   int i;
  if(n%2==0)
  {
    dq.push_back(s[0]);
    dq.push_back(s[1]);
    i=2;
  }
  else
  {
    dq.push_back(s[0]);
    i=1;
  }
  int cnt=0;
  for( ;i<n;i++)
  {
    if(cnt%2==0)dq.push_front(s[i]);
    else dq.push_back(s[i]);
    cnt++;
  }
  while(dq.size())
  {
    cout<<dq.front();
    dq.pop_front();
  }
  cout<<endl;
  return 0;
}