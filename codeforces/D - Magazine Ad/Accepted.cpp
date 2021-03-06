/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2019 19:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 4600 KB                              
*  problem: https://codeforces.com/contest/803/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;cin.ignore();string s;
  getline(cin,s);int mx=0;
  vector<int>v;int cnt=0;
  for(auto x:s)
  {
    if(x==' '||x=='-')
    {
      v.push_back(cnt+1);
      mx=max(mx,cnt+1);cnt=0;
    }
    else cnt++;
  }
  v.push_back(cnt);mx=max(mx,cnt);
   int lo=mx,hi=1e6,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;int cnt=0,cn=0;
    for(int i=0;i<v.size();i++)
    {
      if(v[i]+cnt>md)
      {
        cn++;cnt=v[i];
      }
      else cnt+=v[i];
    }cn++;
    if(cn>n)lo=md;else hi=md;
  }
  for(md=lo;md<=hi;md++)
  {
    int cnt=0,cn=0;
    for(int i=0;i<v.size();i++)
    {
      if(v[i]+cnt>md)
      {
        cn++;cnt=v[i];
      }
      else cnt+=v[i];
    }cn++;
    if(cn<=n)cout<<md<<endl,exit(0);
  }
  return 0;
}