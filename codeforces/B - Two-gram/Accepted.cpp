/****************************************************************************************
*  @author: * kzvd4729                                       created: May/06/2018 20:23                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 30 ms                                           memory_used: 3500 KB                              
*  problem: https://codeforces.com/contest/977/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n;
string s;
map<string,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>s;
   for(int i=0;i<s.size()-1;i++)
    mp[s.substr(i,2)]++;
  map<string,int>::iterator it=mp.begin();
  int mx=0;
  string ans;
  for(;it!=mp.end();it++)
  {
    if(it->second>mx)
    {
      mx=it->second;
      ans=it->first;
    }
  }
  cout<<ans<<endl;
  return 0;
}