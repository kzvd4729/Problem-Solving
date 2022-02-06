/****************************************************************************************
*  @author: kzvd4729                                         created: May/18/2018 20:36                        
*  solution_verdict: Wrong answer on test 30                 language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/982/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>s;
  for(int i=1;i<s.size()-1;i++)
  {
    if(s[i]=='0')continue;
    if(s[i-1]=='1'||s[i+1]=='1')
      cout<<"NO"<<endl,exit(0);
  }
  s="0"+s;
  s=s+"0";
  for(int i=1;i<s.size()-1;i++)
  {
    if(s[i]=='1')continue;
    if(s[i-1]=='0'&&s[i+1]=='0')
      cout<<"NO"<<endl,exit(0);
  }
  cout<<"YES"<<endl;
  return 0;
}