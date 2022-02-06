/****************************************************************************************
*  @author: kzvd4729                                         created: May/18/2019 16:07                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/663/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;getline(cin,s);
  int pl=1,mn=0;
  for(auto x:s)
  {
    if(x=='+')pl++;
    if(x=='-')mn++;
  }
  stringstream str(s);string num;
  while(str>>num);
  stringstream srt(num);int n;srt>>n;
   vector<int>v;
  for(int i=1;i<=pl;i++)
  {
    int mx=(n+mn-(pl-i));
    int now=min(mx,n);
    v.push_back(now);mn-=now;
  }
  if(n+mn!=0)cout<<"Impossible"<<endl,exit(0);
  cout<<"Possible"<<endl;
  int pr=0,pt=0;
  for(auto x:s)
  {
    if(x=='?')
    {
      if(!pr)cout<<v[pt++];
      else cout<<1;
    }
    else
    {
      if(x=='+')pr=0;
      if(x=='-')pr=1;
      cout<<x;
    }
  }
  cout<<endl;
  return 0;
}