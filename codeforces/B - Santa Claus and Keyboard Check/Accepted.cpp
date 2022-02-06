/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/06/2019 12:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/752/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
set<char>st[300];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string a,b;cin>>a>>b;
   for(int i=0;i<a.size();i++)
  {
    if(a[i]==b[i])continue;
     st[a[i]].insert(b[i]);
    st[b[i]].insert(a[i]);
  }
  for(char i='a';i<='z';i++)
    if(st[i].size()>1)cout<<-1<<endl,exit(0);
  for(int i=0;i<b.size();i++)
  {
    if(st[b[i]].size()==0)continue;
    char c=*st[b[i]].begin();b[i]=c;
  }
  if(a!=b)cout<<-1<<endl,exit(0);
  vector<pair<char,char>>ans;
  for(char i='a';i<='z';i++)
  {
    if(st[i].size()==1)
    {
      char c=*st[i].begin();
      ans.push_back({i,c});
      st[c].clear();
    }
  }
  cout<<ans.size()<<endl;
  for(auto x:ans)
    cout<<x.first<<" "<<x.second<<endl;
  return 0;
}