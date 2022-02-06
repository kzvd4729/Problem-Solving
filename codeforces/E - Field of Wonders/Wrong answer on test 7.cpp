/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/26/2018 21:42                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/883/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
map<char,int>fr;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;vector<string>v;
  set<char>rv;
  for(auto x:s)
  {
    if(x=='*')continue;
    rv.insert(x);
  }
  int m;cin>>m;
  while(m--)
  {
    string ss;cin>>ss;int f=0;
    for(int i=0;i<n;i++)
    {
      if(s[i]=='*'&&rv.find(ss[i])!=rv.end())f=1;
      else if(s[i]!='*'&&s[i]!=ss[i])f=1;
    }
    if(f==0)v.push_back(ss);
  }
  //cout<<v.size()<<endl;
  for(auto x:v)
  {
    for(int i=0;i<n;i++)
    {
      if(s[i]=='*')
        fr[x[i]]++;
    }
  }
  int ans=0;
  for(auto x:fr)
    if(x.second==v.size())ans++;
  cout<<ans<<endl;
  return 0;
}