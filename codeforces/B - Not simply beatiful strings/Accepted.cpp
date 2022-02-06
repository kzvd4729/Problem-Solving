/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/23/2018 23:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/955/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int fre[10004];
string s;
vector<char>v;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
   for(int i=0;i<s.size();i++)
  {
    if(fre[s[i]]==0)v.push_back(s[i]);
    fre[s[i]]++;
  }
  if(v.size()==1||v.size()>4)cout<<"No"<<endl,exit(0);
  if(v.size()==2)
  {
    if(fre[v[0]]>=2&&fre[v[1]]>=2)cout<<"Yes"<<endl,exit(0);
    else cout<<"No"<<endl,exit(0);
  }
  if(v.size()==3)
  {
    int cnt=0;
    if(fre[v[0]]>=2)cnt++;
    if(fre[v[1]]>=2)cnt++;
    if(fre[v[2]]>=2)cnt++;
    if(cnt>=1)cout<<"Yes"<<endl,exit(0);
    else cout<<"No"<<endl,exit(0);
  }
  else cout<<"Yes"<<endl;
  return 0;
}