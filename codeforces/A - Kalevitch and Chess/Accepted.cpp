/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/06/2018 19:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/7/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
string s[10];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int f=0;
  for(int i=1;i<=8;i++)
  {
    cin>>s[i];
    for(auto x:s[i])
      if(x=='W')f=1;
  }
  if(f==0)cout<<8<<endl,exit(0);
   int cnt=0;
  for(int i=1;i<=8;i++)
  {
    f=0;
    for(auto x:s[i])
    {
      if(x=='W')f=1;
    }
    if(f==0)cnt++;
  }
   for(int i=1;i<=8;i++)
  {
    f=0;
    for(int j=1;j<=8;j++)
    {
      if(s[j][i-1]=='W')f=1;
    }
    if(f==0)cnt++;
  }
  cout<<cnt<<endl;
  return 0;
}