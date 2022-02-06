/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/13/2019 17:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/1244/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  string s;cin>>s;s=s+s+s;
   int f=0;
  for(int i=n;i<n+n;i++)
    if(s[i]==s[i-1])f=1;
  if(!f)
  {
    if(k%2)for(int i=n;i<n+n;i++)s[i]=(s[i]=='W'?'B':'W');
    for(int i=n;i<n+n;i++)
      cout<<s[i];
    cout<<endl,exit(0);
  }
  vector<int>wh,bl;
  for(int i=1;i<n+n+n;i++)
  {
    if(s[i]=='W'&&s[i-1]=='W')
      wh.push_back(i);
  }
  for(int i=0;i<n+n+n-1;i++)
  {
    if(s[i]=='W'&&s[i+1]=='W')
      wh.push_back(i);
  }
  for(int i=1;i<n+n+n;i++)
  {
    if(s[i]=='B'&&s[i-1]=='B')
      bl.push_back(i);
  }
  for(int i=0;i<n+n+n-1;i++)
  {
    if(s[i]=='B'&&s[i+1]=='B')
      bl.push_back(i);
  }
  sort(wh.begin(),wh.end());sort(bl.begin(),bl.end());
  wh.erase(unique(wh.begin(),wh.end()),wh.end());
  bl.erase(unique(bl.begin(),bl.end()),bl.end());
   for(int i=n;i<n+n;i++)
  {
    int w=2e9,b=2e9,id;
     if(s[i]==s[i-1]||s[i]==s[i+1])
    {
      cout<<s[i];continue;
    }
    id=upper_bound(wh.begin(),wh.end(),i)-wh.begin();
    if(id<wh.size())w=min(w,wh[id]-i);
    id--;
    if(id>=0)w=min(w,i-wh[id]);
     id=upper_bound(bl.begin(),bl.end(),i)-bl.begin();
    if(id<bl.size())b=min(b,bl[id]-i);
    id--;
    if(id>=0)b=min(b,i-bl[id]);
     if(min(w,b)<=k)
    {
      if(w<b)cout<<'W';
      else cout<<'B';
    }
    else
    {
      if(s[i]=='W')
      {
        if(k%2)cout<<'B';
        else cout<<'W';
      }
      else
      {
        if(k%2)cout<<'W';
        else cout<<'B';
      }
    }
  }
  cout<<endl;
  return 0;
}