/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/26/2018 19:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/957/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int l,r,n;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  cin>>s;
  s="#"+s;
  s=s+"#";
   for(int i=1;i<s.size()-2;i++)
  {
    if(s[i]=='?'||s[i+1]=='?')continue;
    if(s[i]==s[i+1])cout<<"No"<<endl,exit(0);
  }
  l=-1,r=-1;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='?')
    {
      if(l==-1)l=i,r=i;
      else r=i;
    }
    else
    {
      if(l!=-1)if(r-l>0||s[l-1]==s[r+1]||s[l-1]=='#'||s[r+1]=='#')cout<<"Yes"<<endl,exit(0);
      l=-1;
      r=-1;
    }
  }
  cout<<"No"<<endl;
  return 0;
}