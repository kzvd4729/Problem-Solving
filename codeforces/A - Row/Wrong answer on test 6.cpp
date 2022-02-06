/****************************************************************************************
*  @author: kzvd4729                                         created: May/18/2018 20:25                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/982/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,one,mx;
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
  for(int i=0;i<s.size();i++)
    if(s[i]=='1')one++;
  mx=(n+1)/2;
  if(one==mx)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
   return 0;
}