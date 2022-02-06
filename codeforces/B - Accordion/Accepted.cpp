/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/11/2019 20:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 1000 KB                              
*  problem: https://codeforces.com/contest/1101/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int a=-1,b=-1,c=-1,d=-1;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='[')
    {
      a=i;break;
    }
  }
  if(a==-1)cout<<-1<<endl,exit(0);
  for(int i=s.size()-1;i>a;i--)
  {
    if(s[i]==']')
    {
      b=i;break;
    }
  }
  if(b==-1)cout<<-1<<endl,exit(0);
  for(int i=a+1;i<b;i++)
  {
    if(s[i]==':')
    {
      c=i;break;
    }
  }
  if(c==-1)cout<<-1<<endl,exit(0);
  for(int i=b-1;i>c;i--)
  {
    if(s[i]==':')
    {
      d=i;break;
    }
  }
  if(d==-1)cout<<-1<<endl,exit(0);
    int cnt=0;
  for(int i=c+1;i<d;i++)
  {
    if(s[i]=='|')
    {
      cnt++;
    }
  }
  cout<<cnt+4<<endl;
  return 0;
}