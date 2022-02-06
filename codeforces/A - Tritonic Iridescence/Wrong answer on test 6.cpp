/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/26/2018 19:35                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3300 KB                              
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
      if(l!=-1)if(s[l-1]==s[r+1]||s[l-1]=='#'||s[r+1]=='#')cout<<"Yes"<<endl,exit(0);
      l=-1;
      r=-1;
    }
  }
  cout<<"No"<<endl;
  return 0;
}