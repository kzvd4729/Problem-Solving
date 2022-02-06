/****************************************************************************************
*  @author: * kzvd4729                                       created: May/14/2019 20:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1165/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,x,y;cin>>n>>x>>y;
  string s;cin>>s;reverse(s.begin(),s.end());
  int cnt=0;
  for(int i=0;i<y;i++)
    if(s[i]=='1')cnt++;
  for(int i=y+1;i<x;i++)
    if(s[i]=='1')cnt++;
  if(s[y]=='0')cnt++;
  cout<<cnt<<endl;
   return 0;
}