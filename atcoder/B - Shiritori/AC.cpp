/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-08 18:07:35                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 2 ms                                            memory_used: 384 KB                               
*  problem: https://atcoder.jp/contests/abc109/tasks/abc109_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
map<string,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s="#",k;
  while(n--)
  {
    cin>>k;
    if(mp[k])cout<<"No"<<endl,exit(0);
    mp[k]=1;
    if(s=="#")
    {
      s=k;
      continue;
    }
    if(k[0]!=s.back())cout<<"No"<<endl,exit(0);
    s=k;
  }
  if(mp[k])cout<<"Yes"<<endl,exit(0);
  return 0;
}