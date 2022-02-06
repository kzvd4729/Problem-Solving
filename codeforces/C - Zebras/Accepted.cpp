/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/19/2018 23:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 452 ms                                          memory_used: 10000 KB                             
*  problem: https://codeforces.com/contest/950/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int id,dd;
string s;
queue<int>zero,one;
vector<int>v[200005];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='0')
    {
      if(!one.size())
      {
        id++;
        v[id].push_back(i+1);
        zero.push(id);
      }
      else
      {
        dd=one.front();
        one.pop();
        v[dd].push_back(i+1);
        zero.push(dd);
      }
    }
    else
    {
      if(!zero.size())
      {
        cout<<-1<<endl;
        return 0;
      }
      else
      {
        dd=zero.front();
        zero.pop();
        v[dd].push_back(i+1);
        one.push(dd);
      }
    }
  }
  if(one.size())
  {
    cout<<-1<<endl;
    return 0;
  }
  cout<<id<<endl;
  for(int i=1;i<=id;i++)
  {
    cout<<v[i].size()<<" ";
    for(auto x:v[i])cout<<x<<" ";
    cout<<endl;
  }
  return 0;
}